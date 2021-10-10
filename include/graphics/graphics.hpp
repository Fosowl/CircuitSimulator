/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-tekspice-martin.legrand
** File description:
** graphics
*/

#ifndef GRAPHICS_HPP_
#define GRAPHICS_HPP_

//#include "raylib.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <memory>

#include "anomaly.hpp"
#include "interface.hpp"
#include "interpreter.hpp"

using string = std::string;
using Unit = nts::AComponent;
using UnitPtr = std::shared_ptr<nts::AComponent>;

class Graphics {
    public:
        Graphics(int width, int height, int fps, const string& name);
        ~Graphics();

        void initComponents(vector<UnitPtr> chipsets);
        bool displayBoard(nts::Interpreter interpreter);
        void updateCircuitState();
    protected:
    private:
        vector<Unit *> chipsets_;
};

#endif /* !GRAPHICS_HPP_ */