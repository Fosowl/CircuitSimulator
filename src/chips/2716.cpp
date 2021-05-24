/*
** EPITECH PROJECT, 2020
** project file
** File description:
** 2716 EPROM chipsets
*/

#include "chips/2716.hpp"

using namespace std;

nts::circuit_2716::circuit_2716()
{
    int nb_pin = 13;

    type = "2716";
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

nts::circuit_2716::~circuit_2716()
{
}

void nts::circuit_2716::simulate(size_t tick)
{
    if (cables["1"].state == TRUE && cables["2"].state == TRUE)
        cables["3"].state = TRUE;
    else if (cables["1"].state != UNDEFINED && cables["2"].state != UNDEFINED)
        cables["3"].state = FALSE;
    if (cables["5"].state == TRUE && cables["6"].state == TRUE)
        cables["4"].state = TRUE;
    else if (cables["5"].state != UNDEFINED && cables["6"].state != UNDEFINED)
        cables["4"].state = FALSE;
    if (cables["8"].state == TRUE && cables["9"].state == TRUE)
        cables["10"].state = TRUE;
    else if (cables["8"].state != UNDEFINED && cables["9"].state != UNDEFINED)
        cables["10"].state = FALSE;
    if (cables["13"].state == TRUE && cables["12"].state == TRUE)
        cables["11"].state = TRUE;
    else if (cables["13"].state != UNDEFINED && cables["12"].state != UNDEFINED)
        cables["11"].state = FALSE;
}

nts::Tristate nts::circuit_2716::compute(std::size_t pin)
{
    return sharedCompute(pin);
}

void nts::circuit_2716::setLink(std::size_t pin, nts::AComponent &other, std::size_t otherPin)
{
    sharedLinker(pin, other, otherPin);
}

void nts::circuit_2716::dump() const
{
    sharedDumper(getName());
}
