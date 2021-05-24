/*
** EPITECH PROJECT, 2020
** project file
** File description:
** interface for AComponent
*/

#include "interface.hpp"
#include "def.hpp"
#include "anomaly.hpp"
#include <exception>

using stringstream = std::stringstream;
using string = std::string;

void nts::AComponent::sharedLinker(size_t pin, AComponent &other, size_t otherPin)
{
    stringstream cvrt_1;
    stringstream cvrt_2;
    cvrt_1 << pin;
    cvrt_2 << otherPin;

    if (!hasCable(cvrt_1.str()))
        throw ntsError(this->getName() + " can't connect to pin " + cvrt_1.str());
    if (!other.hasCable(cvrt_2.str()))
        throw ntsError(other.getName() + " can't connect to pin " + cvrt_2.str());
    this->cables[cvrt_1.str()].pin = &other;
    this->cables[cvrt_1.str()].pin_id = cvrt_2.str();
    this->cables[cvrt_1.str()].chipEntryPins.push_back(cvrt_2.str());
    other.cables[cvrt_2.str()].pin = this;
    other.cables[cvrt_2.str()].pin_id = cvrt_1.str();
    other.cables[cvrt_2.str()].chipEntryPins.push_back(cvrt_1.str());
}

void nts::AComponent::sharedDumper(string name) const noexcept
{
    string state = "Failure";

    std::cout << "-----" << CYAN << name << RESET << "-----" << std::endl;
    for (auto cable : cables) {
        std::cout << "Pin : " << YELLOW << cable.first << RESET << std::endl;
        if (cable.second.state == UNDEFINED)
            state = MAGENTA + "undefined"s;
        if (cable.second.state == TRUE)
            state = GREEN + "true"s;
        if (cable.second.state == FALSE)
            state = RED + "false"s;
        std::cout << "Pin state : " << state << RESET << std::endl;
    }
}

nts::Tristate nts::AComponent::sharedCompute(size_t pin)
{
    return cables[to_string(pin)].state;
}