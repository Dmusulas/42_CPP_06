/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 15:32:25 by dmusulas          #+#    #+#             */
/*   Updated: 2025/07/17 15:41:38 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

// Includes
#include "Data.hpp"
#include <stdint.h>

class Serializer {
private:
    // Orthodox Canonical Form
    // Default constructor
    Serializer();

    // Copy constructor
    Serializer(const Serializer &other);

    // Copy assignment operator
    Serializer &operator=(const Serializer &other);

    // Destructor
    ~Serializer();

public:
    static uintptr_t serialize(Data *ptr);
    static Data *deserialize(uintptr_t raw);
};

#endif
