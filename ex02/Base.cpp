/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:14:38 by dmusulas          #+#    #+#             */
/*   Updated: 2025/07/17 16:20:19 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

// Base class destructor
Base::~Base() {}

// Derived class destructors
A::~A() {}
B::~B() {}
C::~C() {}

// Generate function - randomly creates A, B, or C
Base *generate(void) {
    static bool seeded = false;
    if (!seeded) {
        std::srand(std::time(0));
        seeded = true;
    }

    int random = std::rand() % 3;
    switch (random) {
    case 0:
        return new A();
    case 1:
        return new B();
    case 2:
        return new C();
    default:
        return new A(); // fallback
    }
}

// Identify using pointer
void identify(Base *p) {
    if (dynamic_cast<A *>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B *>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C *>(p)) {
        std::cout << "C" << std::endl;
    } else {
        std::cout << "Unknown type" << std::endl;
    }
}

// Identify using reference (no pointers allowed inside)
void identify(Base &p) {
    try {
        A &a = dynamic_cast<A &>(p);
        (void)a;
        std::cout << "A" << std::endl;
        return;
    } catch (...) {
    }

    try {
        B &b = dynamic_cast<B &>(p);
        (void)b;
        std::cout << "B" << std::endl;
        return;
    } catch (...) {
    }

    try {
        C &c = dynamic_cast<C &>(p);
        (void)c;
        std::cout << "C" << std::endl;
        return;
    } catch (...) {
    }

    std::cout << "Unknown type" << std::endl;
}
