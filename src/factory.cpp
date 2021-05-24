/*
** EPITECH PROJECT, 2020
** project file
** File description:
** components factory
*/

#include "parser.hpp"
#include "interface.hpp"
#include "com.hpp"
#include "chips/2716.hpp"
#include "chips/4001.hpp"
#include "chips/4008.hpp"
#include "chips/4011.hpp"
#include "chips/4013.hpp"
#include "chips/4017.hpp"
#include "chips/4030.hpp"
#include "chips/4040.hpp"
#include "chips/4069.hpp"
#include "chips/4071.hpp"
#include "chips/4081.hpp"
#include "chips/4094.hpp"
#include "chips/4512.hpp"
#include "chips/4514.hpp"
#include "chips/4801.hpp"
#include "anomaly.hpp"
#include <functional>

using Unit = nts::AComponent;
using UnitPtr = std::shared_ptr<nts::AComponent>;

UnitPtr nts::Parser::createComponent(string type)
{
    UnitPtr chip = nullptr;
    map<string, std::function<UnitPtr()>> factoryMap;

    factoryMap["input"] = std::make_unique<com_input>;
    factoryMap["clock"] = std::make_unique<com_clock>;
    factoryMap["true"] = std::make_unique<com_true>;
    factoryMap["false"] = std::make_unique<com_false>;
    factoryMap["output"] = std::make_unique<com_output>;
    factoryMap["2716"] = std::make_unique<circuit_2716>;
    factoryMap["4001"] = std::make_unique<circuit_4001>;
    factoryMap["4008"] = std::make_unique<circuit_4008>;
    factoryMap["4011"] = std::make_unique<circuit_4011>;
    factoryMap["4013"] = std::make_unique<circuit_4013>;
    factoryMap["4017"] = std::make_unique<circuit_4017>;
    factoryMap["4030"] = std::make_unique<circuit_4030>;
    factoryMap["4040"] = std::make_unique<circuit_4040>;
    factoryMap["4069"] = std::make_unique<circuit_4069>;
    factoryMap["4071"] = std::make_unique<circuit_4071>;
    factoryMap["4081"] = std::make_unique<circuit_4081>;
    factoryMap["4094"] = std::make_unique<circuit_4094>;
    factoryMap["4512"] = std::make_unique<circuit_4512>;
    factoryMap["4514"] = std::make_unique<circuit_4514>;
    factoryMap["4801"] = std::make_unique<circuit_4081>;
    if (factoryMap.count(type) == 0)
        throw ntsError("Component : " + type + "not found");
    return factoryMap[type]();
}