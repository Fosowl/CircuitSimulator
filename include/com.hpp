/*
** EPITECH PROJECT, 2020
** project file
** File description:
** input / output component
*/

#ifndef COM_H
#define COM_H

#include "interface.hpp"

using string = std::string;

namespace nts {
    class com_input : public AComponent {
        public:
         com_input();
         ~com_input();
         void simulate(size_t tick);
         Tristate compute(size_t pin);
         void setLink(size_t pin, AComponent &other, size_t otherPin);
         void dump() const;
    };

    class com_clock : public AComponent {
        public:
         com_clock();
         ~com_clock();
         void simulate(size_t tick);
         Tristate compute(size_t pin);
         void setLink(size_t pin, AComponent &other, size_t otherPin);
         void dump() const;

    };

    class com_true : public AComponent {
        public:
         com_true();
         ~com_true();
         void simulate(size_t tick);
         Tristate compute(size_t pin);
         void setLink(size_t pin, AComponent &other, size_t otherPin);
         void dump() const;

    };

    class com_false : public AComponent {
        public:
         com_false();
         ~com_false();
         void simulate(size_t tick);
         Tristate compute(size_t pin);
         void setLink(size_t pin, AComponent &other, size_t otherPin);
         void dump() const;

    };

    class com_output : public AComponent {
        public:
         com_output();
         ~com_output();
         void simulate(size_t tick);
         Tristate compute(size_t pin);
         void setLink(size_t pin, AComponent &other, size_t otherPin);
         void dump() const;

    };
};

#endif /* COM_H */
