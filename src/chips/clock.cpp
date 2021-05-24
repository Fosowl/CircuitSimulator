
/*
** EPITECH PROJECT, 2020
** project file
** File description:
** interface
*/

#include "com.hpp"

using namespace std;

nts::com_clock::com_clock()
{
    type = "clock";
    cables["1"].state = UNDEFINED;
    cables["1"].pin = nullptr;
    cables["1"].output = true;
}

nts::com_clock::~com_clock()
{}

void nts::com_clock::simulate(size_t tick)
{
    if (tick % 2 == 1) {
        cables["1"].state = FALSE;
        return;
    }
    if (tick % 2 == 0) {
        cables["1"].state = TRUE;
        return;
    }
}

nts::Tristate nts::com_clock::compute(std::size_t pin)
{
    return sharedCompute(pin);
}

void nts::com_clock::setLink(std::size_t pin, nts::AComponent &other, std::size_t otherPin)
{
    sharedLinker(pin, other, otherPin);
}

void nts::com_clock::dump() const
{
    sharedDumper(getName());
}
