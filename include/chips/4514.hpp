/*
** EPITECH PROJECT, 2020
** project file
** File description:
** 4514
*/

#ifndef CIR_4514
#define CIR_4514

#include "interface.hpp"

namespace nts {
    class circuit_4514 : public AComponent {
        public:
         circuit_4514();
         ~circuit_4514();
         void simulate(std::size_t tick);
         nts::Tristate compute(std::size_t pin);
         void setLink(std::size_t pin, nts::AComponent &other, std::size_t otherPin);
         void dump() const;
    };
};

#endif
