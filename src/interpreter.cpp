/*
** EPITECH PROJECT, 2020
** project file
** File description:
** Interpreter class method
*/

#include "interpreter.hpp"
#include "def.hpp"
#include "parser.hpp"
#include "anomaly.hpp"
#include <limits.h>

using string = std::string;

using Unit = nts::AComponent;
using UnitPtr = std::shared_ptr<nts::AComponent>;
using mapElement = pair<string, nts::Tristate>;

sig_atomic_t catch_int = 0;

void signalHandler(int signum)
{
    catch_int = 1;
}

nts::Interpreter::Interpreter(vector<UnitPtr> chipsets)
{
    command_ = "";
    tick_ = 0;
    loop_ = false;
    for (auto const& curr : chipsets) {
        auto ptr = curr.get();
        chipsets_.push_back(ptr);
    }
}

int nts::Interpreter::executeCommmand(string command)
{
    int ct = 1;

    if (command == "exit" || command == "EOF")
        ct = 0;
    else if (command == "display")
        this->display();
    else if (command == "simulate") {
            this->simulate();
    } else if (command == "loop") {
        this->loop();
        ct = 0;
    } else if (command == "dump")
        this->dump();
    else if (command.find("=") != string::npos) {
        set_input_stack_.push_back(command);
    } else
        std::cout << "Unknown command : " << command << std::endl;
    return ct;
}

string nts::Interpreter::getCommand()
{
    std::cout << "> ";
    if ((cin >> std::ws >> command_).eof())
        command_ = "EOF";
    return command_;
}

void nts::Interpreter::display()
{
    vector<mapElement> pin_in;
    vector<mapElement> pin_out;
    string pin("1");

    for (auto const& curr : chipsets_) {
        if (!curr->hasCable(pin))
            throw ntsError("Clock doesnt have pin : " + pin);
        if (curr->getType() == "input" || curr->getType() == "false"
          || curr->getType() == "true" || curr->getType() == "clock")
            insertElem(pin_in, curr);
        if (curr->getType() == "output")
            insertElem(pin_out, curr);
    }
    std::cout << "tick: " + to_string(this->tick_) << std::endl;
    std::cout << "input(s):" << std::endl;
    for (auto it_map = pin_in.begin(); it_map != pin_out.end() && it_map != pin_in.end(); ) {
        string pin_val = "U";
        if (it_map->second == TRUE)
            pin_val = "1";
        if (it_map->second == FALSE)
            pin_val = "0";
        std::cout << "\t" + it_map->first + ": " + pin_val << std::endl;
        it_map++;
        if (it_map == pin_in.end()) {
            std::cout << "output(s):" << std::endl;
            it_map = pin_out.begin();
        }
    }
}

void insertElem(vector<mapElement> &elements, const Unit *chip)
{
    string pin("1");
    mapElement tmp = mapElement(chip->getName(), chip->getState(pin));

    if (elements.begin() == elements.end()) {
        elements.push_back(tmp);
        return;
    }
    for (auto it = elements.begin(); it != elements.end(); it++) {
        if (inAlphabeticalOrder(chip->getName(), it->first)) {
            tmp = mapElement(chip->getName(), chip->getState(pin));
            elements.insert(it, tmp);
            return;
        }
    }
    elements.insert(elements.end(), tmp);
}

void nts::Interpreter::setInput(string chip, string input)
{
    nts::Tristate state = UNDEFINED;
    string pin("1");
    map<string, nts::Tristate> adapter;
    bool found = false;

    adapter["0"] = FALSE;
    adapter["1"] = TRUE;
    adapter["U"] = UNDEFINED;
    if (adapter.count(input) == 0)
        throw ntsError("Input doesn't support value : " + input);
    state = adapter[input];
    for (auto const& curr : chipsets_) {
        if (!curr->hasCable(pin))
            throw ntsError("Input doesnt have pin : " + pin);
        if (curr->getType() == "true" || curr->getType() == "false")
            throw ntsError("Can't change state of chip of type : " + curr->getType());
        if (curr->getName() == chip) {
            curr->setState(pin, state);
            found = true;
        }
    }
    if (found == false)
        throw ntsError("Couldn't find chip : " + chip);
}

void nts::Interpreter::simulate()
{
    std::string pin("1");

    tick_++;
    for (auto input : set_input_stack_) {
        vector<string> split = nts::Parser::split_string(input, "=", "=");
        this->setInput(split[0], split[1]);
    }
    if (this->tick_ >= ULONG_MAX) {
        this->tick_ = 0;
        throw ntsError("Clock cycles limit reach"s);
    }
    for (auto const& chip : chipsets_) {
        if (chip->getType() == "output") {
            chip->setState(pin, getElectronFlow(chip, pin));
        }
    }
}

nts::Tristate nts::Interpreter::getElectronFlow(Unit *chip, string targetPin)
{
    nts::Tristate state = nts::UNDEFINED;
    Cable cable;
    auto isCom = [=]() {
        if (chip->getType() == "input" || chip->getType() == "true" 
         || chip->getType() == "false" || chip->getType() == "clock")
            return true;
        return false;
    };

    if (isCom()) {
        chip->simulate(this->tick_);
        return chip->getState("1"s);
    }
    auto InPlugs = chip->getCables();
    for (auto lk = InPlugs.begin(); lk != InPlugs.end(); lk++) {
        if (lk->first == targetPin) {
            cable = lk->second;
            break;
        }
    }
    for (auto entry : cable.chipEntryPins) {
        if (chip->getPlug(entry) == nullptr)
            continue;
        string backLink = chip->getPinID(entry);
        if (backLink == "-1" || (chip->getType() != "output" && backLink == targetPin))
            continue;
        chip->setState(entry, getElectronFlow(chip->getPlug(entry), backLink));
    }
    chip->simulate(this->tick_);
    return chip->getState(targetPin);
}

void nts::Interpreter::loop() noexcept
{
    loop_ = true;
}

void nts::Interpreter::dump() noexcept
{
    for (auto const& curr : chipsets_) {
        curr->dump();
    }
}

bool nts::Interpreter::isLooping() noexcept
{
    if (catch_int)
        loop_ = false;
    catch_int = 0;
    return loop_;
}

bool inAlphabeticalOrder(const string a, const string b)
{
    if (a.compare(b) <= 0)
        return true;
    return false;
}

nts::Interpreter::~Interpreter()
{}