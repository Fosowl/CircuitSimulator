/*
** EPITECH PROJECT, 2020
** project file
** File description:
** interface
*/

#include "com.hpp"

using namespace std;

nts::com_true::com_true()
{
    type = "true";
    cables["1"].state = TRUE;
    cables["1"].pin = nullptr;
    cables["1"].output = false;
}

nts::com_true::~com_true()
{}

void nts::com_true::simulate(size_t tick)
{} // no need to simulate true component

nts::Tristate nts::com_true::compute(std::size_t pin)
{
    return sharedCompute(pin);
}

void nts::com_true::setLink(std::size_t pin, nts::AComponent &other, std::size_t otherPin)
{
    sharedLinker(pin, other, otherPin);
}

void nts::com_true::dump() const
{
    sharedDumper(getName());
}
