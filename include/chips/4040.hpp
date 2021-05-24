/*
** EPITECH PROJECT, 2020
** project file
** File description:
** 4040
*/

#ifndef CIR_4040
#define CIR_4040

#include "interface.hpp"

namespace nts {
    class circuit_4040 : public AComponent {
        public:
         circuit_4040();
         ~circuit_4040();
         void simulate(std::size_t tick);
         nts::Tristate compute(std::size_t pin);
         void setLink(std::size_t pin, nts::AComponent &other, std::size_t otherPin);
         void dump() const;
    };
};

#endif
