/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:52:43 by dmusulas          #+#    #+#             */
/*   Updated: 2025/07/17 15:08:59 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "TypeConverter.hpp"
#include "TypeDetector.hpp"
#include <iostream>

void ScalarConverter::convert(const std::string &literal) {
    LiteralType type = TypeDetector::detectType(literal);

    if (type == INVALID_TYPE) {
        std::cout << "Invalid literal format" << std::endl;
        return;
    }

    TypeConverter::convertAndDisplay(literal, type);
}
