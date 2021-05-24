/*
** EPITECH PROJECT, 2020
** project file
** File description:
** 4514 decoder chipset
*/

#include "chips/4514.hpp"

using namespace std;
using namespace nts;

nts::circuit_4514::circuit_4514()
{
    int nb_pin = 13;
    AComponent::ALogics lg;

    type = "4514";
    for (int i = 0; i <= nb_pin; i++) {
        cables[to_string(i)].state = UNDEFINED;
        cables[to_string(i)].pin = nullptr;
        cables[to_string(i)].output = false;
        cables[to_string(i)].pin_id = "-1";
    }
    // implement connection
}

nts::circuit_4514::~circuit_4514()
{}

void nts::circuit_4514::simulate(size_t tick)
{
    //too implement
}

Tristate nts::circuit_4514::compute(std::size_t pin)
{
    return sharedCompute(pin);
}

void nts::circuit_4514::setLink(std::size_t pin, nts::AComponent &other, std::size_t otherPin)
{
    sharedLinker(pin, other, otherPin);
}

void nts::circuit_4514::dump() const
{
    sharedDumper(getName());
}
