/*
** EPITECH PROJECT, 2020
** project file
** File description:
** 4512
*/

#ifndef CIR_4512
#define CIR_4512

#include "interface.hpp"

namespace nts {
    class circuit_4512 : public AComponent {
        public:
         circuit_4512();
         ~circuit_4512();
         void simulate(std::size_t tick);
         nts::Tristate compute(std::size_t pin);
         void setLink(std::size_t pin, nts::AComponent &other, std::size_t otherPin);
         void dump() const;
    };
}

#endif
