/*
** EPITECH PROJECT, 2021
** B-OOP-400-TLS-4-1-tekspice-martin.legrand
** File description:
** graphics initializer
*/

#include "graphics/graphics.hpp"

Graphics::Graphics(int width, int height, int fps, std::string name)
{
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(width, height, name.c_str());
    SetTargetFPS(fps);
}

Graphics::~Graphics()
{
    CloseWindow();
}

// Public Methods

void Graphics::initComponents(vector<UnitPtr> chipsets)
{

}

void Graphics::updateCircuitState()
{

}

bool Graphics::displayBoard(nts::Interpreter interpreter)
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
    EndDrawing();
    return WindowShouldClose();
}


// Private Methods