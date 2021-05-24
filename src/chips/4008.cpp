/*
** EPITECH PROJECT, 2020
** project file
** File description:
** 4008 4-Bit added chipset
*/

#include "chips/4008.hpp"

using namespace std;

nts::circuit_4008::circuit_4008()
{
    int nb_pin = 15;

    type = "4008";
    for (int i = 0; i <= nb_pin; i++) {
        cables[to_string(i)].state = UNDEFINED;
        cables[to_string(i)].pin = nullptr;
        cables[to_string(i)].output = false;
        cables[to_string(i)].pin_id = "-1";
    }
    cables["10"].output = true;
    cables["10"].chipEntryPins.push_back("6");
    cables["10"].chipEntryPins.push_back("7");
    cables["10"].chipEntryPins.push_back("8");
    cables["11"].output = true;
    cables["11"].chipEntryPins.push_back("4");
    cables["11"].chipEntryPins.push_back("5");
    cables["11"].chipEntryPins.push_back("10");
    cables["12"].output = true;
    cables["12"].chipEntryPins.push_back("2");
    cables["12"].chipEntryPins.push_back("3");
    cables["12"].chipEntryPins.push_back("11");
    cables["13"].output = true;
    cables["13"].chipEntryPins.push_back("15");
    cables["13"].chipEntryPins.push_back("1");
    cables["13"].chipEntryPins.push_back("12");
}

nts::circuit_4008::~circuit_4008()
{}

void nts::circuit_4008::simulate(size_t tick)
{
    if (cables["6"].state == TRUE && cables["7"].state == TRUE && cables["8"].state == TRUE)
        cables["10"].state = TRUE;
    else if (cables["6"].state != UNDEFINED && cables["7"].state != UNDEFINED && cables["8"].state != UNDEFINED)
        cables["10"].state = FALSE;

    if (cables["4"].state == TRUE && cables["5"].state == TRUE && cables["10"].state == TRUE)
        cables["11"].state = TRUE;
    else if (cables["4"].state != UNDEFINED && cables["5"].state != UNDEFINED && cables["10"].state != UNDEFINED)
        cables["11"].state = FALSE;

    if (cables["2"].state == TRUE && cables["3"].state == TRUE && cables["11"].state == TRUE)
        cables["12"].state = TRUE;
    else if (cables["2"].state != UNDEFINED && cables["3"].state != UNDEFINED && cables["11"].state != UNDEFINED)
        cables["12"].state = FALSE;

    if (cables["15"].state == TRUE && cables["1"].state == TRUE && cables["12"].state == TRUE)
        cables["13"].state = TRUE;
    else if (cables["15"].state != UNDEFINED && cables["1"].state != UNDEFINED && cables["12"].state != UNDEFINED)
        cables["13"].state = FALSE;
}

nts::Tristate nts::circuit_4008::compute(std::size_t pin)
{
    return sharedCompute(pin);
}

void nts::circuit_4008::setLink(std::size_t pin, nts::AComponent &other, std::size_t otherPin)
{
    sharedLinker(pin, other, otherPin);
}

void nts::circuit_4008::dump() const
{
    sharedDumper(getName());
}

