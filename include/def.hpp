/*
** EPITECH PROJECT, 2020
** project file
** File description:
** multiple define for program
*/

#ifndef ERROR_H
#define ERROR_H

#include <exception>
#include <iostream>

#define DEBUG_ENABLED true
#define ERR_ABORT true

#define MAX(x, y) (x > y ? x : y)
#define MIN(x, y) (x < y ? x : y)
#define INT(x) static_cast<int>(x)
#define FLOAT(x) static_cast<float>(x)
#define DOUBLE(x) static_cast<double>(x)

#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

#define ROUND(X) X + (X & 1)
#define IS_POWER_2(X) !(X & (X-1))

#define DBG(X) if (DEBUG_ENABLED) std::cout << YELLOW << "[Debug] " << RESET << X << std::endl;
#define ERROR(X) if (DEBUG_ENABLED) std::cerr << RED << "[Error] " << RESET << X << std::endl;
#define WARNING(X) if (DEBUG_ENABLED) std::cout << YELLOW << "[Warning] " << RESET << X << std::endl;
#define PRINT(X) std::cout << CYAN << X << RESET << std::endl;
#define ABORT(err) if (ERR_ABORT) exit(err);

#define SIGINT_CATCH "SIGINT_CATCH"

#endif
