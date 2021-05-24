/*
** EPITECH PROJECT, 2020
** project file
** File description:
** 4030
*/

#ifndef CIR_4030
#define CIR_4030

#include "interface.hpp"

namespace nts {
    class circuit_4030 : public AComponent {
        public:
         circuit_4030();
         ~circuit_4030();
         void simulate(std::size_t tick);
         nts::Tristate compute(std::size_t pin);
         void setLink(std::size_t pin, nts::AComponent &other, std::size_t otherPin);
         void dump() const;
    };
};
#endif
