/*
** EPITECH PROJECT, 2020
** project file
** File description:
** 4801
*/

#ifndef CIR_4801
#define CIR_4801

#include "interface.hpp"

namespace nts {
    class circuit_4801 : public AComponent {
        public:
         circuit_4801();
         ~circuit_4801();
         void simulate(std::size_t tick);
         nts::Tristate compute(std::size_t pin);
         void setLink(std::size_t pin, nts::AComponent &other, std::size_t otherPin);
         void dump() const;
    };
};

#endif
