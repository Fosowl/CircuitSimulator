/*
** EPITECH PROJECT, 2020
** project file
** File description:
** 4081
*/

#ifndef CIR_4081
#define CIR_4081

#include "interface.hpp"

namespace nts {
    class circuit_4081 : public AComponent {
        public:
         circuit_4081();
         ~circuit_4081();
         void simulate(std::size_t tick);
         nts::Tristate compute(std::size_t pin);
         void setLink(std::size_t pin, nts::AComponent &other, std::size_t otherPin);
         void dump() const;
    };
};
#endif
