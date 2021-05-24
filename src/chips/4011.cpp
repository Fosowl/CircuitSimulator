/*
** EPITECH PROJECT, 2020
** project file
** File description:
** 4011 CMOS NAND gate chipset
*/

#include "chips/4011.hpp"

using namespace std;

nts::circuit_4011::circuit_4011()
{
    int nb_pin = 13;

    type = "4011";
    for (int i = 0; i <= nb_pin; i++) {
        cables[to_string(i)].state = UNDEFINED;
        cables[to_string(i)].pin = nullptr;
        cables[to_string(i)].output = false;
        cables[to_string(i)].pin_id = "-1";
    }
    cables["6"].output = true;
    cables["6"].chipEntryPins.push_back("3");
    cables["6"].chipEntryPins.push_back("4");
    cables["6"].chipEntryPins.push_back("5");
    cables["9"].output = true;
    cables["9"].chipEntryPins.push_back("1");
    cables["9"].chipEntryPins.push_back("2");
    cables["9"].chipEntryPins.push_back("8");
    cables["10"].output = true;
    cables["10"].chipEntryPins.push_back("13");
    cables["10"].chipEntryPins.push_back("12");
    cables["10"].chipEntryPins.push_back("11");
}

nts::circuit_4011::~circuit_4011()
{}

void nts::circuit_4011::simulate(size_t tick)
{
    if (TRIPLE_NAND_GATE(cables["3"].state, cables["4"].state, cables["5"].state))
        cables["6"].state = TRUE;
    else if (cables["3"].state != UNDEFINED && cables["4"].state != UNDEFINED && cables["5"].state != UNDEFINED)
        cables["6"].state = FALSE;

    if (TRIPLE_NAND_GATE(cables["1"].state, cables["2"].state, cables["8"].state))
        cables["9"].state = TRUE;
    else if (cables["1"].state != UNDEFINED && cables["2"].state != UNDEFINED && cables["8"].state != UNDEFINED)
        cables["9"].state = FALSE;

    if (TRIPLE_NAND_GATE(cables["13"].state, cables["12"].state, cables["11"].state))
        cables["10"].state = TRUE;
    else if (cables["13"].state != UNDEFINED && cables["12"].state != UNDEFINED && cables["11"].state != UNDEFINED)
        cables["10"].state = FALSE;
}

nts::Tristate nts::circuit_4011::compute(std::size_t pin)
{
    return sharedCompute(pin);
}

void nts::circuit_4011::setLink(std::size_t pin, nts::AComponent &other, std::size_t otherPin)
{
    sharedLinker(pin, other, otherPin);
}

void nts::circuit_4011::dump() const
{
    sharedDumper(getName());
}
