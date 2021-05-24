/*
** EPITECH PROJECT, 2020
** project file
** File description:
** 4071 OR gate chipset
*/

#include "chips/4071.hpp"

using namespace std;
using namespace nts;

nts::circuit_4071::circuit_4071()
{
    int nb_pin = 13;

    type = "4071";
    for (int i = 0; i <= nb_pin; i++) {
        cables[to_string(i)].state = UNDEFINED;
        cables[to_string(i)].pin = nullptr;
        cables[to_string(i)].output = false;
        cables[to_string(i)].pin_id = "-1";
    }
    cables["3"].output = true;
    cables["3"].chipEntryPins.push_back("1");
    cables["3"].chipEntryPins.push_back("2");
    cables["4"].output = true;
    cables["4"].chipEntryPins.push_back("5");
    cables["4"].chipEntryPins.push_back("6");
    cables["10"].output = true;
    cables["10"].chipEntryPins.push_back("8");
    cables["10"].chipEntryPins.push_back("9");
    cables["11"].output = true;
    cables["11"].chipEntryPins.push_back("12");
    cables["11"].chipEntryPins.push_back("13");
}

nts::circuit_4071::~circuit_4071()
{}

void nts::circuit_4071::simulate(size_t tick)
{
    if (OR_GATE(cables["1"].state, cables["2"].state))
        cables["3"].state = TRUE;
    else if (cables["1"].state != UNDEFINED && cables["2"].state != UNDEFINED)
        cables["3"].state = FALSE;

    if (OR_GATE(cables["5"].state, cables["6"].state))
        cables["4"].state = TRUE;
    else if (cables["5"].state != UNDEFINED && cables["6"].state != UNDEFINED)
        cables["4"].state = FALSE;

    if (OR_GATE(cables["8"].state, cables["9"].state))
        cables["10"].state = TRUE;
    else if (cables["8"].state != UNDEFINED && cables["9"].state != UNDEFINED)
        cables["10"].state = FALSE;

    if (OR_GATE(cables["13"].state, cables["12"].state))
        cables["11"].state = TRUE;
    else if (cables["13"].state != UNDEFINED && cables["12"].state != UNDEFINED)
        cables["11"].state = FALSE;
}

nts::Tristate nts::circuit_4071::compute(std::size_t pin)
{
    return sharedCompute(pin);
}

void nts::circuit_4071::setLink(std::size_t pin, nts::AComponent &other, std::size_t otherPin)
{
    sharedLinker(pin, other, otherPin);
}

void nts::circuit_4071::dump() const
{
    sharedDumper(getName());
}
