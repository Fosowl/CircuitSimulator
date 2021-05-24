/*
** EPITECH PROJECT, 2020
** project file
** File description:
** 2716
*/

#ifndef CIR_2716
#define CIR_2716

#include "interface.hpp"

namespace nts {
    class circuit_2716 : public AComponent {
        public:
         circuit_2716();
         ~circuit_2716();
         void simulate(std::size_t tick);
         nts::Tristate compute(std::size_t pin);
         void setLink(std::size_t pin, nts::AComponent &other, std::size_t otherPin);
         void dump() const;
    };
};

#endif
