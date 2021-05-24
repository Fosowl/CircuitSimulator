/*
** EPITECH PROJECT, 2020
** project file
** File description:
** nts file parser
*/

#include "parser.hpp"
#include "interface.hpp"
#include "anomaly.hpp"

using string = std::string;

using Unit = nts::AComponent;

nts::Parser::Parser(string filename)
{
    ifstream file(filename);
    string content;
    vector<string> lines;
    string mode = "none";
    vector<string>::iterator it;

    if (!file.good())
        throw ntsError("Can't open file " + filename);
    getline(file, content, '\0');
    lines = this->split_string(content, "\n", "\t");
    for (it = lines.begin(); it != lines.end(); it++) {
        if (it->find(".chipsets:", *it->end()) != string::npos) {
            mode = "chipsets";
            continue;
        } else if (it->find(".links:", *it->end()) != string::npos) {
            mode = "links";
            continue;
        }
        if (mode == "links" && (*it)[(*it).find_first_not_of(" ")] != '#') {
            this->remove_comment(*it);
            links_section.push_back(*it);
        }
        if (mode == "chipsets" && (*it)[(*it).find_first_not_of(" ")] != '#') {
            this->remove_comment(*it);
            chipsets_section.push_back(*it);
        }
    }
    file.close();
}

void nts::Parser::remove_comment(string &str)
{
    size_t pos = str.find("#");
    str = str.substr(0, pos);
}

vector<string> nts::Parser::split_string(string str, string delim, string delim2)
{
    vector<string> lines;
    unsigned int pos = 0;
    unsigned int sp = 0;
    string token;
    string curr_delim;
    const char *literal;

    while (pos != string::npos) {
        sp = 0;
        literal = str.c_str();
        if (literal[0] == delim.c_str()[0] || literal[0] == delim2.c_str()[0])
            str.erase(0, 1);
        if (str.find(delim, *str.end()) != string::npos) {
            pos = str.find(delim);
            curr_delim = delim;
        } else {
            curr_delim = delim2;
            pos = str.find(delim2);
        }
        if (str == "")
            break;
        token = str.substr(0, pos);
        lines.push_back(token);
        while (str[sp+pos+1] == curr_delim[0])
            sp++;
        str.erase(0, pos + sp + delim.length());
    }
    return lines;
}

vector<UnitPtr> nts::Parser::getChipsets()
{
    vector<string> words;

    if (!chipsets_section.size() || !links_section.size())
        throw ntsError("no chipset or link section");
    for (string curr : chipsets_section) {
        words = split_string(curr, " ", "\t");
        if (words.size() != 2)
            throw ntsError("Bad chipset format");
        if (hasChipset(words[1]))
            throw ntsError(words[1] + " chipset name already used.");
        auto chip = createComponent(words[0]);
        chipsets.push_back(std::move(chip));
        chipsets.back()->setName(words[1]);
    }
    for (string curr : links_section) {
        words = split_string(curr, " ", "\t");
        if (words.size() != 2)
            throw ntsError("No space separator for parsing links");
        vector<string> pinned_1 = split_string(words[0], ":", "\t");
        vector<string> pinned_2 = split_string(words[1], ":", "\t");
        if (pinned_1.size() != 2 || pinned_2.size() != 2)
            throw ntsError("Format incorrect : <" + curr + ">");
        linkChipsets(pinned_1, pinned_2);
    }
    return chipsets;
}

bool nts::Parser::hasChipset(string name)
{
    for (auto const &curr : chipsets) {
        if (curr->getName() == name)
            return true;
    }
    return false;
}

void nts::Parser::linkChipsets(vector<string> pin_cf_1, vector<string> pin_cf_2)
{
    bool found = false;

    for (auto const &curr : chipsets) {
        if (curr->getName() != pin_cf_1[0])
            continue;
        for (auto const &nest : chipsets) {
            if (nest->getName() != pin_cf_2[0])
                continue;
            found = true;
            if (!curr->hasCable(pin_cf_1[1]))
                throw ntsError("chip : " + pin_cf_1[0] + " doesn''t have pin : " + pin_cf_1[1]);
            if (!curr->hasCable(pin_cf_1[1]))
                throw ntsError("chip : " + pin_cf_2[0] + " doesn't have pin : " + pin_cf_2[1]);
            curr->setLink(atoi(pin_cf_1[1].c_str()), *nest, atoi(pin_cf_2[1].c_str()));
        }
    }
    if (!found)
        throw ntsError("Unknown component name  : " + pin_cf_1[0] + " or " + pin_cf_2[0]);
}

nts::Parser::~Parser()
{}
