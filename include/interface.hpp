/*
** EPITECH PROJECT, 2020
** project file
** File description:
** pure virtual interface IComponent and herited AComponent
*/

#ifndef INTERFACE_H
#define INTERFACE_H

#include <list>
#include <map>
#include <string>
#include <vector>
#include <sstream>
#include "gate.hpp"

struct LogicUnit {
    std::vector<bool> input;
    bool output;
};

using namespace std;
using LogicTable = std::vector<LogicUnit *>;

namespace nts{
    class AComponent;
    class IComponent;

    enum Tristate {
        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false
    };

    struct Cable {
        AComponent *pin;
        string pin_id;
        std::vector<string> chipEntryPins;
        bool output;
        Tristate state;
    };

    class IComponent {
        public:
            IComponent() = default;

            virtual ~IComponent() = default;
            virtual void simulate(size_t tick) = 0;
            virtual Tristate compute(size_t pin) = 0;
            virtual void setLink(size_t pin, AComponent &other, size_t otherPin) = 0;
            virtual void dump() const = 0;
        protected:
            map<string, Cable> cables;
            string type;
            string name;
    };

    class AComponent : public IComponent {
        public:
            void sharedLinker(size_t pin, AComponent &other, size_t otherPin);
            void sharedDumper(const string& name) const noexcept;
            Tristate sharedCompute(size_t pin);

            string getName() const { return name; };
            void setName(string& _name) { name = _name; };

            string getType() const { return type; };
            void setType(string& _type) { type = _type; };

            bool hasCable(const string& name) { return cables.find(name) != cables.end(); };

            Tristate getState(const string& _name) const { return cables.find(_name)->second.state; };
            void setState(string &_name, Tristate _state) { cables[_name].state = _state; };

            AComponent *getPlug(const string& name) { return cables[name].pin; };
            string getPinID(const string& name) { return cables[name].pin_id; };
            map<string, Cable> getCables() const { return cables; };

            class ALogics {
                public:
                    void SR_latch(nts::Tristate R, nts::Tristate S,
                                        nts::Tristate &Q, nts::Tristate &Q_);
                    
                    LogicUnit *makeTruth(bool input[], bool output, int size);
                    bool getTableThruthFor(bool input[], LogicTable in, int size);
            };
        protected:
            LogicTable *table_;
    };

}

#endif /* INTERFACE_H */
