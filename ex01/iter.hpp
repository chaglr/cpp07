#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>

//void iter: The function's name is iter, and it returns nothing (void).
//T* arr: The first parameter is a pointer to an array of type T.
//std::size_t len: The second parameter is the length of the array. std::size_t is an unsigned integer type used for array indexing and sizes.
//void (*func)(const T&): The third parameter is a function pointer. This points to a function that takes a constant reference to a T type and returns nothing (void).
//The function iter takes an array, its length, and a function pointer. It then iterates over the array and calls the function on each element.

template <typename T>
void iter(T* arr, std::size_t len, void (*func)(const T&))
{
        for (std::size_t i = 0; i < len; i++)
		func(arr[i]);
}
#endif