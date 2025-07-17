/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TypeDetector.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 18:40:18 by dmusulas          #+#    #+#             */
/*   Updated: 2025/07/15 18:40:19 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDETECTOR_HPP
#define TYPEDETECTOR_HPP

#include <string>

enum LiteralType { CHAR_TYPE, INT_TYPE, FLOAT_TYPE, DOUBLE_TYPE, INVALID_TYPE };

class TypeDetector {
private:
    TypeDetector();

public:
    static LiteralType detectType(const std::string &literal);
    static bool isChar(const std::string &literal);
    static bool isInt(const std::string &literal);
    static bool isFloat(const std::string &literal);
    static bool isDouble(const std::string &literal);
};

#endif
