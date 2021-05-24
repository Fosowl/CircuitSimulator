/*
** EPITECH PROJECT, 2020
** project file
** File description:
** interpreter
*/

#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <string>
#include <vector>
#include <memory>
#include <csignal>
#include "anomaly.hpp"
#include "interface.hpp"

using string = std::string;
using Unit = nts::AComponent;
using UnitPtr = std::shared_ptr<nts::AComponent>;

namespace nts {
    class Interpreter {
        public:
            Interpreter(vector<UnitPtr> chipsets);
            ~Interpreter();
            int executeCommmand(string command);
            string getCommand();
            void exit();
            void display();
            void setInput(string chip, string input);
            void simulate();
            void loop() noexcept;
            void dump() noexcept;
            bool isLooping() noexcept;
            Tristate getElectronFlow(Unit *chip, string pin);
            string getPinnedName(Unit *on, Unit *to) const;
        private:
            size_t tick_;
            string command_;
            bool loop_;
            vector<string> set_input_stack_;
            vector<Unit *> chipsets_;
    };
}

using mapElement = pair<string, nts::Tristate>;

bool inAlphabeticalOrder(const string a, const string b);
void signalHandler(int signum);
void insertElem(vector<mapElement> &elements, const Unit *chip);

#endif
