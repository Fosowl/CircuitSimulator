/*
** EPITECH PROJECT, 2020
** project file
** File description:
** parser class
*/

#ifndef PARSE_H
#define PARSE_H

#include <algorithm>
#include <string>
#include <exception>
#include <list>
#include <vector>
#include <iostream>
#include <fstream>
#include <memory>
#include "interface.hpp"
#include <functional>
#include <unordered_map>

using string = std::string;

using Unit = nts::AComponent;
using UnitPtr = std::shared_ptr<nts::AComponent>;

namespace nts {
    class Parser {
        public:
            Parser(const string& filename);
            ~Parser();
            vector<UnitPtr> getChipsets();
            void linkChipsets(vector<string> pin_1, vector<string> pin_2);
            static vector<string> split_string(string str, string delim, string delim2);
            void remove_comment(string& str);
            void makeFactory();
            UnitPtr createComponent(string type);
            bool hasChipset(const string& name);
        private:
            string filename;
            vector<shared_ptr<Unit>> chipsets;
            vector<string> chipsets_section;
            vector<string> links_section;
    };
}

#endif /* PARSE_H */
