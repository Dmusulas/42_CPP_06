/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 15:48:00 by dmusulas          #+#    #+#             */
/*   Updated: 2025/07/17 15:49:26 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

int main() {
    // Create a Data object with some values
    Data *original = new Data();
    original->age = 25;
    original->firstName = "John";
    original->lastName = "Doe";
    original->student = true;

    std::cout << "=== SERIALIZATION TEST ===" << std::endl;

    // Show original data
    std::cout << "Original pointer: " << original << std::endl;
    std::cout << "Original data:" << std::endl;
    std::cout << "  Age: " << original->age << std::endl;
    std::cout << "  Name: " << original->firstName << " " << original->lastName
              << std::endl;
    std::cout << "  Student: " << (original->student ? "Yes" : "No")
              << std::endl;
    std::cout << std::endl;

    // Serialize the pointer
    uintptr_t serialized = Serializer::serialize(original);
    std::cout << "Serialized value: " << serialized << std::endl;
    std::cout << std::endl;

    // Deserialize back to pointer
    Data *deserialized = Serializer::deserialize(serialized);
    std::cout << "Deserialized pointer: " << deserialized << std::endl;
    std::cout << std::endl;

    // Test if pointers are equal
    std::cout << "=== VERIFICATION ===" << std::endl;
    if (original == deserialized) {
        std::cout << "✓ SUCCESS: Pointers are equal!" << std::endl;
    } else {
        std::cout << "✗ FAILURE: Pointers are different!" << std::endl;
    }

    // Show that we can still access the data through deserialized pointer
    std::cout << "Data through deserialized pointer:" << std::endl;
    std::cout << "  Age: " << deserialized->age << std::endl;
    std::cout << "  Name: " << deserialized->firstName << " "
              << deserialized->lastName << std::endl;
    std::cout << "  Student: " << (deserialized->student ? "Yes" : "No")
              << std::endl;

    // Clean up memory
    delete original;

    return 0;
}
