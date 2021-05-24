/*
** EPITECH PROJECT, 2020
** project file
** File description:
** interface
*/

#include "com.hpp"

using namespace std;

nts::com_false::com_false()
{
    cables["1"].state = FALSE;
    cables["1"].pin = nullptr;
    cables["1"].output = false;
    type = "false";
}

nts::com_false::~com_false()
{}

void nts::com_false::simulate(size_t tick)
{} // no need to simulate false

nts::Tristate nts::com_false::compute(std::size_t pin)
{
    return sharedCompute(pin);
}

void nts::com_false::setLink(std::size_t pin, nts::AComponent &other, std::size_t otherPin)
{
    sharedLinker(pin, other, otherPin);
}

void nts::com_false::dump() const
{
    sharedDumper(getName());
}
