/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:52:41 by dmusulas          #+#    #+#             */
/*   Updated: 2025/07/15 18:00:35 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

// Includes
#include <string>

class ScalarConverter {
private:
    // Orthodox Canonical Form
    // Default constructor
    ScalarConverter();
    // Copy constructor
    ScalarConverter(const ScalarConverter &other);

    // Copy assignment operator
    ScalarConverter &operator=(const ScalarConverter &other);

    // Destructor
    ~ScalarConverter();

public:
    static void convert(const std::string &literal);
};

#endif
