/*
** EPITECH PROJECT, 2020
** project file
** File description:
** 4094
*/

#ifndef CIR_4094
#define CIR_4094

#include "interface.hpp"

namespace nts {
    class circuit_4094 : public AComponent {
        public:
         circuit_4094();
         ~circuit_4094();
         void simulate(std::size_t tick);
         nts::Tristate compute(std::size_t pin);
         void setLink(std::size_t pin, nts::AComponent &other, std::size_t otherPin);
         void dump() const;
    };
};

#endif
