/*
** EPITECH PROJECT, 2020
** project file
** File description:
** 4017
*/

#ifndef CIR_4017
#define CIR_4017

#include "interface.hpp"

namespace nts {
    class circuit_4017 : public AComponent {
        public:
         circuit_4017();
         ~circuit_4017();
         void simulate(std::size_t tick);
         nts::Tristate compute(std::size_t pin);
         void setLink(std::size_t pin, nts::AComponent &other, std::size_t otherPin);
         void dump() const;
    };
};

#endif
