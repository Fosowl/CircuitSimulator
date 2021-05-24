/*
** EPITECH PROJECT, 2020
** project file
** File description:
** 4001
*/

#ifndef CIR_4001
#define CIR_4001

#include "interface.hpp"

namespace nts {
    class circuit_4001 : public AComponent {
        public:
         circuit_4001();
         ~circuit_4001();
         void simulate(std::size_t tick);
         nts::Tristate compute(std::size_t pin);
         void setLink(std::size_t pin, nts::AComponent &other, std::size_t otherPin);
         void dump() const;

    };
};

#endif

