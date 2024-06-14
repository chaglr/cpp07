#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>

template <typename T>
void iter(T* arr, size_t length, void (*f)(T&))
{
	for (size_t i = 0; i < length; i++)
		f(arr[i]);
}

// Const version
template <typename T>
void iter(const T* array, std::size_t length, void (*func)(const T&)) {
	for (std::size_t i = 0; i < length; ++i) {
		func(array[i]);
	}
}

#endif