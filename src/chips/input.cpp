/*
** EPITECH PROJECT, 2020
** project file
** File description:
** interface
*/

#include "com.hpp"

using namespace std;

nts::com_input::com_input()
{
    type = "input";
    cables["1"].state = UNDEFINED;
    cables["1"].pin = nullptr;
    cables["1"].output = false;
    cables["1"].pin_id = -1;
}

nts::com_input::~com_input()
{}

void nts::com_input::simulate(size_t tick)
{} // no need to simulate input

nts::Tristate nts::com_input::compute(size_t pin)
{
    return sharedCompute(pin);
}

void nts::com_input::setLink(size_t pin, nts::AComponent &other, size_t otherPin)
{
    sharedLinker(pin, other, otherPin);
}

void nts::com_input::dump() const
{
    sharedDumper(getName());
}