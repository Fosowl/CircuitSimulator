/*
** EPITECH PROJECT, 2020
** project file
** File description:
** 4801 memory chipset
*/

#include "chips/4801.hpp"

using namespace std;

nts::circuit_4801::circuit_4801()
{
    int nb_pin = 13;

    type = "4801";
    for (int i = 0; i <= nb_pin; i++) {
        cables[to_string(i)].state = UNDEFINED;
        cables[to_string(i)].pin = nullptr;
        cables[to_string(i)].output = false;
        cables[to_string(i)].pin_id = "-1";
    }
    // implement connection
}

nts::circuit_4801::~circuit_4801()
{}

void nts::circuit_4801::simulate(size_t tick)
{
    // to implement
}

nts::Tristate nts::circuit_4801::compute(std::size_t pin)
{
    return sharedCompute(pin);
}

void nts::circuit_4801::setLink(std::size_t pin, nts::AComponent &other, std::size_t otherPin)
{
    sharedLinker(pin, other, otherPin);
}

void nts::circuit_4801::dump() const
{
    sharedDumper(getName());
}
