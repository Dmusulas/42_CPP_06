/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TypeConverter.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 13:48:22 by dmusulas          #+#    #+#             */
/*   Updated: 2025/07/17 15:24:43 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TypeConverter.hpp"
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>

void TypeConverter::convertFromChar(char c) {
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;

    float f = static_cast<float>(c);
    double d = static_cast<double>(c);
    std::cout.precision(1);
    std::cout.setf(std::ios::fixed);
    std::cout << "float: " << f << "f" << std::endl;

    std::cout << "double: " << d << std::endl;

    std::cout.unsetf(std::ios::fixed);
}

void TypeConverter::convertFromInt(int value) {
    char c = static_cast<char>(value);
    float f = static_cast<float>(value);
    double d = static_cast<double>(value);

    if (value >= 0 && value <= 127 && std::isprint(c)) {
        std::cout << "char: '" << c << "'" << std::endl;
    } else {
        std::cout << "char: Non displayable" << std::endl;
    }

    std::cout << "int: " << value << std::endl;

    std::cout.setf(std::ios::fixed);
    std::cout.precision(1);
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;

    std::cout.unsetf(std::ios::fixed);
}

void TypeConverter::convertFromFloat(float value) {
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

    std::cout.setf(std::ios::fixed);
    std::cout.precision(1);
    std::cout << "float: " << value << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(value) << std::endl;
    std::cout.unsetf(std::ios::fixed);
}

void TypeConverter::convertFromSpecialFloat(const std::string &literal) {
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

void TypeConverter::convertFromDouble(double value) {
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
        std::cout << "float: " << std::fixed << std::setprecision(1)
                  << static_cast<float>(value) << "f" << std::endl;
    }

    std::cout << "double: " << std::fixed << std::setprecision(1) << value
              << std::endl;
}

void TypeConverter::convertFromSpecialDouble(const std::string &literal) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;

    if (literal == "nan") {
        std::cout << "float: nanf" << std::endl;
    } else if (literal == "+inf") {
        std::cout << "float: +inff" << std::endl;
    } else if (literal == "-inf") {
        std::cout << "float: -inff" << std::endl;
    }

    std::cout << "double: " << std::fixed << std::setprecision(1) << literal
              << std::endl;
}

void TypeConverter::convertAndDisplay(const std::string &literal,
                                      LiteralType type) {
    switch (type) {
    case CHAR_TYPE: {
        if (literal.length() == 3) {

            char c = literal[1];
            convertFromChar(c);
        } else {
            convertFromChar(literal[0]);
        }
        break;
    }
    case INT_TYPE: {
        int value = std::atoi(literal.c_str());
        convertFromInt(value);
        break;
    }
    case FLOAT_TYPE: {
        if (literal == "nanf" || literal == "+inff" || literal == "-inff") {
            convertFromSpecialFloat(literal);
        } else {
            std::string withoutF = literal.substr(0, literal.length() - 1);
            float value = std::atof(withoutF.c_str());
            convertFromFloat(value);
        }
        break;
    }
    case DOUBLE_TYPE: {
        if (literal == "nan" || literal == "+inf" || literal == "-inf") {
            convertFromSpecialDouble(literal);
        } else {
            double value = std::atof(literal.c_str());
            convertFromDouble(value);
        }
        break;
    }
    default:
        std::cout << "Invalid type" << std::endl;
    }
}
