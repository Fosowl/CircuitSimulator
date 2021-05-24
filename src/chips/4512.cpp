/*
** EPITECH PROJECT, 2020
** project file
** File description:
** 4512 selector chipset
*/

#include "chips/4512.hpp"

using namespace std;
using namespace nts;

nts::circuit_4512::circuit_4512()
{
    int nb_pin = 13;

    type = "4512";
    for (int i = 0; i <= nb_pin; i++) {
        cables[to_string(i)].state = UNDEFINED;
        cables[to_string(i)].pin = nullptr;
        cables[to_string(i)].output = false;
        cables[to_string(i)].pin_id = "-1";
    }
    // implement connection
}

nts::circuit_4512::~circuit_4512()
{}

void nts::circuit_4512::simulate(size_t tick)
{
    // to implement
}

Tristate nts::circuit_4512::compute(std::size_t pin)
{
    return sharedCompute(pin);
}

void nts::circuit_4512::setLink(std::size_t pin, nts::AComponent &other, std::size_t otherPin)
{
    sharedLinker(pin, other, otherPin);
}

void nts::circuit_4512::dump() const
{
    sharedDumper(getName());
}
