/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 13:54:54 by dmusulas          #+#    #+#             */
/*   Updated: 2025/07/17 15:24:11 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

void test() {
    std::cout << "Testing ScalarConverter with various literals:" << std::endl;
    std::cout << "1. From chars" << std::endl;
    ScalarConverter::convert("'a'");
    std::cout << std::endl;
    ScalarConverter::convert("'b'");
    std::cout << std::endl;
    ScalarConverter::convert("'~'");
    std::cout << std::endl;
    ScalarConverter::convert("')'");
    std::cout << std::endl;
    std::cout << "2. From integers" << std::endl;
    ScalarConverter::convert("123");
    std::cout << std::endl;
    ScalarConverter::convert("2147483647"); // INT_MAX
    std::cout << std::endl;
    ScalarConverter::convert("-2147483648"); // INT_MIN
    std::cout << std::endl;
    std::cout << "3. From floats" << std::endl;
    ScalarConverter::convert("123.5f");
    std::cout << std::endl;
    ScalarConverter::convert("42.42f");
    std::cout << std::endl;
    ScalarConverter::convert("-123.5f");
    std::cout << std::endl;
    std::cout << "4. From doubles" << std::endl;
    ScalarConverter::convert("123.0");
    std::cout << std::endl;
    ScalarConverter::convert("0.0");
    std::cout << std::endl;
    ScalarConverter::convert("-42.24");
    std::cout << std::endl;
    std::cout << "Done!" << std::endl;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <literal>" << std::endl;
        return 1;
    }

    if (std::string(argv[1]) == "test") {
        test();
    } else {
        ScalarConverter::convert(argv[1]);
    }
    return 0;
}
