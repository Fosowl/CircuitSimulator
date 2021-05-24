/*
** EPITECH PROJECT, 2020
** project file
** File description:
** 4040 12-Bit binary counter chipset
*/

#include "chips/4040.hpp"

using namespace std;

nts::circuit_4040::circuit_4040()
{
    int nb_pin = 13;

    type = "4040";
    for (int i = 0; i <= nb_pin; i++) {
        cables[to_string(i)].state = UNDEFINED;
        cables[to_string(i)].pin = nullptr;
        cables[to_string(i)].output = false;
        cables[to_string(i)].pin_id = "-1";
    }
    // need implementation entry pins
}

nts::circuit_4040::~circuit_4040()
{}

void nts::circuit_4040::simulate(size_t tick)
{
    // not implement yet
}

nts::Tristate nts::circuit_4040::compute(std::size_t pin)
{
    return sharedCompute(pin);
}

void nts::circuit_4040::setLink(std::size_t pin, nts::AComponent &other, std::size_t otherPin)
{
    sharedLinker(pin, other, otherPin);
}

void nts::circuit_4040::dump() const
{
    sharedDumper(getName());
}
