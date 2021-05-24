/*
** EPITECH PROJECT, 2020
** project file
** File description:
** 4011
*/


#ifndef CIR_4011
#define CIR_4011

#include "interface.hpp"

namespace nts {
    class circuit_4011 : public AComponent {
        public:
         circuit_4011();
         ~circuit_4011();
         void simulate(std::size_t tick);
         nts::Tristate compute(std::size_t pin);
         void setLink(std::size_t pin, nts::AComponent &other, std::size_t otherPin);
         void dump() const;

    };
};

#endif
