#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <stdexcept>

template <typename T>
class Array {
private:
	T* elements;
	std::size_t length;

public:
	// Default constructor
	Array() : elements(nullptr), length(0) {}

	// Constructor with size parameter
	Array(unsigned int n) : elements(new T[n]()), length(n) {}

	// Copy constructor
	Array(const Array& other) : elements(new T[other.length]), length(other.length) {
		for (std::size_t i = 0; i < length; ++i) {
			elements[i] = other.elements[i];
		}
	}

	// Destructor
	~Array() {
		delete[] elements;
	}

	// Assignment operator
	Array& operator=(const Array& other) {
		if (this != &other) {
			delete[] elements;
			length = other.length;
			elements = new T[length];
			for (std::size_t i = 0; i < length; ++i) {
				elements[i] = other.elements[i];
			}
		}
		return *this;
	}

	// Subscript operator
	T& operator[](std::size_t index) {
		if (index >= length) {
			throw std::out_of_range("Index out of bounds");
		}
		return elements[index];
	}

	const T& operator[](std::size_t index) const {
		if (index >= length) {
			throw std::out_of_range("Index out of bounds");
		}
		return elements[index];
	}

	// Size function
	std::size_t size() const {
		return length;
	}
};

#endif
