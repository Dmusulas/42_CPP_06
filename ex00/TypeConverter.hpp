/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TypeConverter.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 13:48:02 by dmusulas          #+#    #+#             */
/*   Updated: 2025/07/17 13:48:03 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPECONVERTER_HPP
#define TYPECONVERTER_HPP

#include "TypeDetector.hpp"
#include <string>

class TypeConverter {
private:
    TypeConverter();

public:
    static void convertAndDisplay(const std::string &literal, LiteralType type);

private:
    static void convertFromChar(char c);
    static void convertFromInt(int value);
    static void convertFromFloat(float value);
    static void convertFromDouble(double value);
    static void convertFromSpecialFloat(const std::string &literal);
    static void convertFromSpecialDouble(const std::string &literal);
};

#endif
