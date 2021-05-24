/*
** EPITECH PROJECT, 2020
** project file
** File description:
** 4094 bit-shift chipset
*/

#include "chips/4094.hpp"

using namespace std;

nts::circuit_4094::circuit_4094()
{
    int nb_pin = 13;

    type = "4094";
    for (int i = 0; i <= nb_pin; i++) {
        cables[to_string(i)].state = UNDEFINED;
        cables[to_string(i)].pin = nullptr;
        cables[to_string(i)].output = false;
        cables[to_string(i)].pin_id = "-1";
    }
    // add connection
}

nts::circuit_4094::~circuit_4094()
{}

// not finished
void nts::circuit_4094::simulate(size_t tick)
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
}

nts::Tristate nts::circuit_4094::compute(std::size_t pin)
{
    return sharedCompute(pin);
}

void nts::circuit_4094::setLink(std::size_t pin, nts::AComponent &other, std::size_t otherPin)
{
    sharedLinker(pin, other, otherPin);
}

void nts::circuit_4094::dump() const
{
    sharedDumper(getName());
}
