/*
** EPITECH PROJECT, 2020
** project file
** File description:
** 4013 Dual flip-flop chipset
*/

#include "chips/4013.hpp"

using namespace std;

nts::circuit_4013::circuit_4013()
{
    int nb_pin = 13;

    type = "4013";
    for (int i = 0; i <= nb_pin; i++) {
        cables[to_string(i)].state = UNDEFINED;
        cables[to_string(i)].output = false;
        cables[to_string(i)].pin_id = "-1";
    }
    cables["1"].output = true;
    cables["1"].chipEntryPins.push_back("4");
    cables["1"].chipEntryPins.push_back("5");
    cables["1"].chipEntryPins.push_back("6");
    cables["2"].output = true;
    cables["2"].chipEntryPins.push_back("4");
    cables["2"].chipEntryPins.push_back("5");
    cables["2"].chipEntryPins.push_back("6");
}

nts::circuit_4013::~circuit_4013()
{}

void nts::circuit_4013::simulate(size_t tick)
{
    AComponent::ALogics logics1;
    AComponent::ALogics logics2;
    nts::Tristate reset;
    nts::Tristate data;
    nts::Tristate set;
    nts::Tristate Q;
    nts::Tristate Q_;

    set = cables["6"].state;
    if (cables["3"].state == TRUE && set == TRUE) {
        reset = cables["4"].state;
        data = cables["5"].state;
        logics1.SR_latch(reset, data, Q, Q_);
        cables["1"].state = Q;
        cables["2"].state = Q_;
    }
    set = cables["8"].state;
    if (cables["11"].state == TRUE && set == TRUE) {
        reset = cables["10"].state;
        data = cables["9"].state;
        logics2.SR_latch(reset, data, Q, Q_);
        cables["13"].state = Q;
        cables["12"].state = Q_;
    }
}

nts::Tristate nts::circuit_4013::compute(std::size_t pin)
{
    return sharedCompute(pin);
}

void nts::circuit_4013::setLink(std::size_t pin, nts::AComponent &other, std::size_t otherPin)
{
    sharedLinker(pin, other, otherPin);
}

void nts::circuit_4013::dump() const
{
    sharedDumper(getName());
}
