

#ifndef MATH_MATH_HPP
#define MATH_MATH_HPP
#pragma once
#include <iostream>
#include <limits>
#include <stdexcept>
#include <sstream>

void run();

constexpr double calculate_power(double base, int64_t exponent) {
    if (exponent == 0) return 1.0;
    if (exponent < 0) {
        if (base == 0.0) throw std::domain_error("0 to negative power");
        return 1.0 / calculate_power(base, -exponent);
    }
    double result = 1.0;
    while (exponent > 0) {
        if (exponent & 1) result *= base;
        base *= base;
        exponent >>= 1;
    }
    return result;
}

constexpr double calculate(double x, char op, double y) {
    switch (op) {
        case '+': { return x + y; }
        case '-': { return x - y; }
        case '*': { return x * y; }
        case '/': {
            if (y == 0) {
                std::cout << "Error: Divide by zero!\n";
                return std::numeric_limits<double>::quiet_NaN();
            }
            return x / y;
        }
        case '^': { return calculate_power(x, y); }
        default: {
            std::cout << "Error: Unsupported operator '" << op << "'. Use +, -, *, /, ^\n";
            return std::numeric_limits<double>::quiet_NaN();
        }
    }
}


#endif //MATH_MATH_HPP