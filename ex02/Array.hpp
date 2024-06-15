#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <stdexcept>
#include <iostream>

template <typename T>
class Array {
private:
	T* data;
	std::size_t length;

public:
	// Default constructor
	Array() : data(nullptr), length(0) {}

	// Constructor with size
	explicit Array(std::size_t n) : data(nullptr), length(n) {
		if (n > 0) {
			data = new T[n]();
		}
	}

	// Copy constructor
	Array(const Array& other) : data(nullptr), length(other.length) {
		if (length > 0) {
			data = new T[length];
			for (std::size_t i = 0; i < length; ++i) {
				data[i] = other.data[i];
			}
		}
	}

	// Copy assignment operator
	Array& operator=(const Array& other) {
		if (this != &other) {
			T* newData = other.length > 0 ? new T[other.length] : nullptr;
			for (std::size_t i = 0; i < other.length; ++i) {
				newData[i] = other.data[i];
			}
			delete[] data;
			data = newData;
			length = other.length;
		}
		return *this;
	}

	// Destructor
	~Array() {
		delete[] data;
	}

	// Access operator
	T& operator[](std::size_t index) {
		if (index >= length) {
			throw std::out_of_range("Index out of bounds");
		}
		return data[index];
	}

	const T& operator[](std::size_t index) const {
		if (index >= length) {
			throw std::out_of_range("Index out of bounds");
		}
		return data[index];
	}

	// Size method
	std::size_t size() const {
		return length;
	}
};

// Overloading the output operator for Array class
template <typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& array) {
	os << "[";
	for (std::size_t i = 0; i < array.size(); ++i) {
		os << array[i];
		if (i < array.size() - 1) {
			os << ", ";
		}
	}
	os << "]";
	return os;
}

#endif // ARRAY_HPP
