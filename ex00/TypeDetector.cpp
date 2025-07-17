/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TypeDetector.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 13:42:51 by dmusulas          #+#    #+#             */
/*   Updated: 2025/07/17 15:09:11 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TypeDetector.hpp"
#include <iostream>
#include <sstream>
bool TypeDetector::isChar(const std::string &literal) {
    if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'' &&
        literal[1] >= 32 && literal[1] <= 126)
        return true;
    else if (literal.length() == 1 && literal[0] >= 32 && literal[0] <= 126) {
        // Handle single character literals
        return true;
    }
    return false;
}

bool TypeDetector::isInt(const std::string &literal) {
    std::istringstream iss(literal);
    int value;
    iss >> value;

    return iss.eof() && !iss.fail();
}

bool TypeDetector::isFloat(const std::string &literal) {
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

bool TypeDetector::isDouble(const std::string &literal) {
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

LiteralType TypeDetector::detectType(const std::string &literal) {
    // Check char first
    if (isChar(literal))
        return CHAR_TYPE;

    if (isInt(literal))
        return INT_TYPE;

    if (isFloat(literal))
        return FLOAT_TYPE;

    // Check double (includes special double values)
    if (isDouble(literal))
        return DOUBLE_TYPE;

    return INVALID_TYPE;
}
