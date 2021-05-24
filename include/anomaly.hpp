/*
** EPITECH PROJECT, 2020
** project file
** File description:
** error handling
*/

#include <exception>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>

#ifndef ANOMALY_H
#define ANOMALY_H

using string = std::string;

namespace nts {
    class ntsError : std::exception {
        public:
            ntsError(const string& msg) {
                msg_ = msg;
            }
            const string getError() const throw() {
                return(msg_);
            }
        private:
            string msg_;
    };
};

#endif /* ANOMALY_H */
