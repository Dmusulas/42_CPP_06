/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:52:43 by dmusulas          #+#    #+#             */
/*   Updated: 2025/07/15 18:37:42 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib>
#include <iostream>
#include <limits>
#include <sstream>

// Anonymous namespace for helper functions
// NOTE: It doesn't contradict norm because I am not using keyword 'using'
namespace {
bool isChar(const std::string &literal) {
    return literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'';
}

bool isInt(const std::string &literal) {
    std::istringstream iss(literal);
    int value;
    iss >> value;

    return iss.eof() && !iss.fail();
}

bool isFloat(const std::string &literal) {
    if (literal.empty())
        return false;

    if (literal == "nanf" || literal == "+inff" || literal == "-inff")
        return true;

    size_t len = literal.length();
    if (literal[len - 1] != 'f')
        return false;

    std::string withoutF = literal.substr(0, len - 1);
    std::istringstream iss(withoutF);
    float value;
    iss >> value;
    return iss.eof() && !iss.fail();
}

bool isDouble(const std::string &literal) {
    if (literal.empty())
        return false;

    if (literal == "nan" || literal == "+inf" || literal == "-inf")
        return true;

    size_t len = literal.length();
    if (literal[len - 1] == 'f')
        return false;

    std::istringstream iss(literal);
    double value;
    iss >> value;
    return iss.eof() && !iss.fail();
}

void convertFromChar(char c) {
    std::cout << "char: '" << c << "'" << std::endl;

    std::cout << "int: " << static_cast<int>(c) << std::endl;

    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;

    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void convertFromInt(int value) {
    char c = static_cast<char>(value);
    float f = static_cast<float>(value);
    double d = static_cast<double>(value);

    if (value >= 0 && value <= 127 && std::isprint(c)) {
        std::cout << "char: '" << c << "'" << std::endl;
    } else {
        std::cout << "char: Non displayable" << std::endl;
    }

    std::cout << "int: " << value << std::endl;
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}

void convertFromFloat(float value) {
    // float -> char
    if (value < 0 || value > 127 || value != static_cast<int>(value)) {
        std::cout << "char: impossible" << std::endl;
    } else {
        char c = static_cast<char>(value);
        if (std::isprint(c)) {
            std::cout << "char: '" << c << "'" << std::endl;
        } else {
            std::cout << "char: Non displayable" << std::endl;
        }
    }

    if (value > std::numeric_limits<int>::max() ||
        value < std::numeric_limits<int>::min()) {
        std::cout << "int: impossible" << std::endl;
    } else {
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    }

    // float -> float (same)
    std::cout << "float: " << value << "f" << std::endl;

    // float -> double
    std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void convertFromSpecialFloat(const std::string &literal) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;

    std::cout << "float: " << literal << std::endl;

    if (literal == "nanf") {
        std::cout << "double: nan" << std::endl;
    } else if (literal == "+inff") {
        std::cout << "double: +inf" << std::endl;
    } else if (literal == "-inff") {
        std::cout << "double: -inf" << std::endl;
    }
}

void convertFromDouble(double value) {
    if (value < 0 || value > 127 || value != static_cast<int>(value)) {
        std::cout << "char: impossible" << std::endl;
    } else {
        char c = static_cast<char>(value);
        if (std::isprint(c)) {
            std::cout << "char: '" << c << "'" << std::endl;
        } else {
            std::cout << "char: Non displayable" << std::endl;
        }
    }

    if (value > std::numeric_limits<int>::max() ||
        value < std::numeric_limits<int>::min()) {
        std::cout << "int: impossible" << std::endl;
    } else {
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    }

    if (value > std::numeric_limits<float>::max() ||
        value < -std::numeric_limits<float>::max()) {
        std::cout << "float: impossible" << std::endl;
    } else {
        std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
    }

    std::cout << "double: " << value << std::endl;
}

static void convertFromSpecialDouble(const std::string &literal) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;

    if (literal == "nan") {
        std::cout << "float: nanf" << std::endl;
    } else if (literal == "+inf") {
        std::cout << "float: +inff" << std::endl;
    } else if (literal == "-inf") {
        std::cout << "float: -inff" << std::endl;
    }

    std::cout << "double: " << literal << std::endl;
}

} // namespace

void ScalarConverter::convert(const std::string &literal) {
    if (isChar(literal)) {
        char c = literal[1];
        convertFromChar(c);
    } else if (isInt(literal)) {
        int value = std::atoi(literal.c_str());
        convertFromInt(value);
    } else if (isFloat(literal)) {
        // Handle special cases
        if (literal == "nanf" || literal == "+inff" || literal == "-inff") {
            convertFromSpecialFloat(literal);
        } else {
            std::string withoutF = literal.substr(0, literal.length() - 1);
            float value = std::atof(withoutF.c_str());
            convertFromFloat(value);
        }
    } else if (isDouble(literal)) {
        // Handle special cases
        if (literal == "nan" || literal == "+inf" || literal == "-inf") {
            convertFromSpecialDouble(literal);
        } else {
            double value = std::atof(literal.c_str());
            convertFromDouble(value);
        }
    } else {
        std::cout << "Invalid literal format" << std::endl;
    }
}
