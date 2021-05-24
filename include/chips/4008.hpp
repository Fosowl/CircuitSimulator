/*
** EPITECH PROJECT, 2020
** project file
** File description:
** 4008
*/

#ifndef CIR_4008
#define CIR_4008

#include "interface.hpp"

namespace nts {
    class circuit_4008 : public AComponent {
        public:
         circuit_4008();
         ~circuit_4008();
         void simulate(std::size_t tick);
         nts::Tristate compute(std::size_t pin);
         void setLink(std::size_t pin, nts::AComponent &other, std::size_t otherPin);
         void dump() const;
    };
};

#endif
