/*
** EPITECH PROJECT, 2020
** project file
** File description:
** internal chipsets logics
*/

#include "interface.hpp"
#include "gate.hpp"
#include "def.hpp"

using ctx =  nts::AComponent::ALogics;

void ctx::SR_latch(nts::Tristate R, nts::Tristate S,
                                        nts::Tristate &Q, nts::Tristate &Q_) 
{
    static int state = 0;

    if (R == TRUE && S == TRUE) {
        Q = UNDEFINED;
        Q_ = UNDEFINED;
        return;
    }
    if (R == TRUE)
        state = 0;
    if (S == TRUE)
        state = 1;
    if (state == 0) {
        Q_ = TRUE;
        Q = FALSE;
    } else {
        Q_ = FALSE;
        Q = TRUE;
    }
}

LogicUnit *makeTruth(bool input[], bool output, int size)
{
    vector<bool> tmp_vector;
    LogicUnit *unit = new LogicUnit;

    if (unit == nullptr) {
        ERROR("Memory allocation failure")
        return nullptr;
    }
    for (int i = 0; i < size; i++)
        tmp_vector.push_back(input[i]);
    unit->input = tmp_vector;
    unit->output = output;
    return unit;
}

bool ctx::getTableThruthFor(bool input[], LogicTable in, int size)
{
    for (auto line : in) {
        auto entry = line->input;
        bool ok = true;
        for (int i = 0; i < size; i++) {
            if (input[i] != entry[i]) {
                ok = false;
                break;
            }
        }
        if (ok == true)
            return line->output;
    }
    WARNING("No table entry found !")
    return false;
}