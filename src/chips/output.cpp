

/*
** EPITECH PROJECT, 2020
** project file
** File description:
** interface
*/

#include "com.hpp"

using namespace std;

nts::com_output::com_output()
{
    type = "output";
    cables["1"].state = UNDEFINED;
    cables["1"].pin = nullptr;
    cables["1"].output = false;
    cables["1"].chipEntryPins.push_back("1");
}

nts::com_output::~com_output()
{}

void nts::com_output::simulate(size_t tick)
{} // no need to simulate output

nts::Tristate nts::com_output::compute(std::size_t pin)
{
    return sharedCompute(pin);
}

void nts::com_output::setLink(std::size_t pin, nts::AComponent &other, std::size_t otherPin)
{
    sharedLinker(pin, other, otherPin);
}

void nts::com_output::dump() const
{
    sharedDumper(getName());
}