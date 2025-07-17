/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:17:48 by dmusulas          #+#    #+#             */
/*   Updated: 2025/07/17 16:18:14 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>

int main() {
    // Generate a random Base object
    Base *base = generate();

    // Identify using pointer
    std::cout << "Identify using pointer: ";
    identify(base);

    // Identify using reference
    std::cout << "Identify using reference: ";
    identify(*base);

    // Clean up
    delete base;

    return 0;
}
