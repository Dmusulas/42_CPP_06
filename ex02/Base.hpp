/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmusulas <dmusulas@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 15:54:26 by dmusulas          #+#    #+#             */
/*   Updated: 2025/07/17 16:10:06 by dmusulas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

class Base {
public:
    virtual ~Base();
};

class A : public Base {
public:
    virtual ~A();
};

class B : public Base {
public:
    virtual ~B();
};

class C : public Base {
public:
    virtual ~C();
};

// Function declarations
Base *generate(void);
void identify(Base *p);
void identify(Base &p);

#endif
