/*
** EPITECH PROJECT, 2020
** project file
** File description:
** program start, simulation handling
*/

#include <memory>

#include "def.hpp"
#include "anomaly.hpp"
#include "parser.hpp"
#include "interface.hpp"
#include "interpreter.hpp"
#include "graphics/graphics.hpp"

using string = std::string;

using Unit = nts::AComponent;
using UnitPtr = shared_ptr<nts::AComponent>;

void start_simulation(vector<UnitPtr> chipsets);

int main(int ac, char **argv) {
    vector<UnitPtr> chipsets;

    if (ac != 2) {
        std::cout << "bad number of arguments\n";
        return (84);
    }
    try {
        nts::Parser parser(argv[1]);
        chipsets = parser.getChipsets();
    } catch (const nts::ntsError& e) {
        std::cerr << "ntsError >> " << e.getError() << std::endl;
        return (84);
    }
    try {
        start_simulation(chipsets);
    } catch (const nts::ntsError& e) {
        if (e.getError() == SIGINT_CATCH) {
            std::cout << "caught SIGINT exiting..." << std::endl;
        } else {
            std::cerr << "Fatal: " << e.getError() << std::endl;
        }
    }
    return (0);
}

void start_simulation(vector<UnitPtr> chipsets)
{
    nts::Interpreter sim(chipsets);
    string command;
    bool loop_use;

sim_loop:
    signal(SIGINT, signalHandler);
    loop_use = false;

    while ((command = sim.getCommand()) != "stop") {
        try {
            if (!sim.executeCommmand(command))
                break;
        } catch (const nts::ntsError& e) {
            if (e.getError() == SIGINT_CATCH)
                throw e;
            std::cout << e.getError() << std::endl;
        }
    }
    while (sim.isLooping()) {
        sim.simulate();
        loop_use = true;
    }
    if (loop_use == true)
        goto sim_loop;
}