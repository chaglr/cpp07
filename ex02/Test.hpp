/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhnal <muhnal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 20:51:51 by muhnal            #+#    #+#             */
/*   Updated: 2024/07/28 20:51:52 by muhnal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef TEST_HPP
#define TEST_HPP

#include <iostream>
#include <string>

class Test {
public:
	int value;

	// Default constructor
	Test(int val = 0) : value(val) {
		std::cout << "Constructing Test with value " << value << std::endl;
	}

	// Copy constructor
	Test(const Test& other) : value(other.value) {
		std::cout << "Copying Test with value " << value << std::endl;
	}

	// Assignment operator
	Test& operator=(const Test& other) {
		if (this != &other) {
			std::cout << "Assigning Test with value " << other.value << std::endl;
			value = other.value;
		}
		return *this;
	}

	// Destructor
	~Test() {
		std::cout << "Destroying Test with value " << value << std::endl;
	}

	// String representation
	std::string toString() const {
		return "Test(" + std::to_string(value) + ")";
	}
};

#endif // TEST_HPP
