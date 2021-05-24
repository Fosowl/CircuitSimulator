/*
** EPITECH PROJECT, 2020
** project file
** File description:
** 4071
*/

#ifndef CIR_4071
#define CIR_4071

#include "interface.hpp"

namespace nts {
    class circuit_4071 : public AComponent {
        public:
         circuit_4071();
         ~circuit_4071();
         void simulate(std::size_t tick);
         nts::Tristate compute(std::size_t pin);
         void setLink(std::size_t pin, nts::AComponent &other, std::size_t otherPin);
         void dump() const;
    };
};

#endif
