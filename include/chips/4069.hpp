/*
** EPITECH PROJECT, 2020
** project file
** File description:
** 4069
*/

#ifndef CIR_4069
#define CIR_4069

#include "interface.hpp"

namespace nts {
    class circuit_4069 : public AComponent {
        public:
         circuit_4069();
         ~circuit_4069();
         void simulate(std::size_t tick);
         nts::Tristate compute(std::size_t pin);
         void setLink(std::size_t pin, nts::AComponent &other, std::size_t otherPin);
         void dump() const;
    };
}

#endif
