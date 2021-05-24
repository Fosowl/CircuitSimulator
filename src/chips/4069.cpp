/*
** EPITECH PROJECT, 2020
** project file
** File description:
** 4069 inverter chipset
*/

#include "interface.hpp"
#include "chips/4069.hpp"

using namespace std;

nts::circuit_4069::circuit_4069()
{
    int nb_pin = 13;

    type = "4069";
    for (int i = 0; i <= nb_pin; i++) {
        cables[to_string(i)].state = UNDEFINED;
        cables[to_string(i)].pin = nullptr;
        cables[to_string(i)].output = false;
        cables[to_string(i)].pin_id = "-1";
    }
    cables["2"].output = true;
    cables["2"].chipEntryPins.push_back("1");
    cables["4"].output = true;
    cables["4"].chipEntryPins.push_back("3");
    cables["6"].output = true;
    cables["6"].chipEntryPins.push_back("5");
    cables["12"].output = true;
    cables["12"].chipEntryPins.push_back("13");
    cables["10"].output = true;
    cables["10"].chipEntryPins.push_back("11");
    cables["8"].output = true;
    cables["8"].chipEntryPins.push_back("9");
}

nts::circuit_4069::~circuit_4069()
{}

void nts::circuit_4069::simulate(size_t tick)
{
    if (cables["1"].state != UNDEFINED)
        cables["2"].state = NOT_GATE(cables["1"].state);
    if (cables["3"].state != UNDEFINED)
        cables["4"].state = NOT_GATE(cables["3"].state);
    if (cables["5"].state != UNDEFINED)
        cables["6"].state = NOT_GATE(cables["5"].state);
    if (cables["13"].state != UNDEFINED)
        cables["12"].state = NOT_GATE(cables["13"].state);
    if (cables["11"].state != UNDEFINED)
        cables["10"].state = NOT_GATE(cables["11"].state);
    if (cables["9"].state != UNDEFINED)
        cables["8"].state = NOT_GATE(cables["9"].state);
}

nts::Tristate nts::circuit_4069::compute(std::size_t pin)
{
    return sharedCompute(pin);
}

void nts::circuit_4069::setLink(std::size_t pin, nts::AComponent &other, std::size_t otherPin)
{
    sharedLinker(pin, other, otherPin);
}

void nts::circuit_4069::dump() const
{
    sharedDumper(getName());
}
