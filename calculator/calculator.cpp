//
// Created by Tatiana on 8/16/25.
//

#include "calculator.h"

#include <cmath>
#include <iostream>
#include <string>


bool ReadNumber(Number& result) {
    if (std::cin >> result) {
        return true;
    }

    std::cin.clear();
    std::string bad;
    std::cin >> bad;

    std::cerr << "Error: Numeric operand expected" << std::endl;
    return false;
}

bool RunCalculatorCycle() {
    Number current_value;

    if (!ReadNumber(current_value)) {
        return false;
    }

    Number mem_value = 0.0;
    bool has_mem = false;

    for (std::string token; std::cin >> token; ) {
        if (token == "q") {
            return true;
        } else if (token == "=") {
            std::cout << current_value << std::endl;

        } else if (token == ":") {
            if (!ReadNumber(current_value)) {
                return false;
            }

        } else if (token == "c") {
            current_value = 0.0;

        } else if (token == "s") {
            has_mem = true;
            mem_value = current_value;

        } else if (token == "l") {
            if (!has_mem) {
                std::cerr << "Error: Memory is empty" << std::endl;
                return false;
            }
            current_value = mem_value;

        } else if (token == "+") {
            Number number;
            if (!ReadNumber(number)) return false;
            current_value += number;

        } else if (token == "-") {
            Number number;
            if (!ReadNumber(number)) return false;
            current_value -= number;

        } else if (token == "*") {
            Number number;
            if (!ReadNumber(number)) return false;
            current_value *= number;

        } else if (token == "/") {
            Number number;
            if (!ReadNumber(number)) return false;
            current_value /= number;

        } else if (token == "**") {
            Number number;
            if (!ReadNumber(number)) return false;
            current_value = std::pow(current_value, number);

        } else {
            std::cerr << "Error: Unknown token " << token << std::endl;
            return false;
        }
    }

    return true;
}

