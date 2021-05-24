/*
** EPITECH PROJECT, 2020
** project file
** File description:
** 4013
*/

#ifndef CIR_4013
#define CIR_4013

#include "interface.hpp"

namespace nts {
    class circuit_4013 : public AComponent {
        public:
         circuit_4013();
         ~circuit_4013();
         void simulate(std::size_t tick);
         nts::Tristate compute(std::size_t pin);
         void setLink(std::size_t pin, nts::AComponent &other, std::size_t otherPin);
         void dump() const;
    };
};

#endif
