/*
** EPITECH PROJECT, 2020
** project file
** File description:
** 4017 johnson decade counter chipset
*/

#include "chips/4017.hpp"

using namespace std;

nts::circuit_4017::circuit_4017()
{
    int nb_pin = 13;

    type = "4017";
    for (int i = 0; i <= nb_pin; i++) {
        cables[to_string(i)].state = UNDEFINED;
        cables[to_string(i)].pin = nullptr;
        cables[to_string(i)].output = false;
        cables[to_string(i)].pin_id = "-1";
    }

    cables["1"].chipEntryPins.push_back("13");
    cables["1"].chipEntryPins.push_back("14");
    cables["1"].chipEntryPins.push_back("15");

    cables["2"].chipEntryPins.push_back("13");
    cables["2"].chipEntryPins.push_back("14");
    cables["2"].chipEntryPins.push_back("15");

    cables["3"].chipEntryPins.push_back("13");
    cables["3"].chipEntryPins.push_back("14");
    cables["3"].chipEntryPins.push_back("15");

    cables["4"].chipEntryPins.push_back("13");
    cables["4"].chipEntryPins.push_back("14");
    cables["4"].chipEntryPins.push_back("15");

    cables["5"].chipEntryPins.push_back("13");
    cables["5"].chipEntryPins.push_back("14");
    cables["5"].chipEntryPins.push_back("15");

    cables["6"].chipEntryPins.push_back("13");
    cables["6"].chipEntryPins.push_back("14");
    cables["6"].chipEntryPins.push_back("15");

    cables["7"].chipEntryPins.push_back("13");
    cables["7"].chipEntryPins.push_back("14");
    cables["7"].chipEntryPins.push_back("15");

    cables["8"].chipEntryPins.push_back("13");
    cables["8"].chipEntryPins.push_back("14");
    cables["8"].chipEntryPins.push_back("15");

    cables["9"].chipEntryPins.push_back("13");
    cables["9"].chipEntryPins.push_back("14");
    cables["9"].chipEntryPins.push_back("15");

    cables["10"].chipEntryPins.push_back("13");
    cables["10"].chipEntryPins.push_back("14");
    cables["10"].chipEntryPins.push_back("15");

    cables["11"].chipEntryPins.push_back("13");
    cables["11"].chipEntryPins.push_back("14");
    cables["11"].chipEntryPins.push_back("15");

    cables["12"].chipEntryPins.push_back("13");
    cables["12"].chipEntryPins.push_back("14");
    cables["12"].chipEntryPins.push_back("15");
}

nts::circuit_4017::~circuit_4017()
{}

void nts::circuit_4017::simulate(size_t tick)
{
    static int counter = 0;

    if (counter > 10)
        counter = 0;
    if (cables["15"].state == TRUE)
        counter = 0;
    if (cables["14"].state == TRUE && cables["13"].state == FALSE)
        counter++;
    else if (cables["14"].state == TRUE && cables["13"].state == TRUE)
        counter++;
    // add counter output
}

nts::Tristate nts::circuit_4017::compute(std::size_t pin)
{
    return sharedCompute(pin);
}

void nts::circuit_4017::setLink(std::size_t pin, nts::AComponent &other, std::size_t otherPin)
{
    sharedLinker(pin, other, otherPin);
}

void nts::circuit_4017::dump() const
{
    sharedDumper(getName());
}
