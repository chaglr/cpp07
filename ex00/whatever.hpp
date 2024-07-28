#ifndef WHATEVER_HPP
#define WHATEVER_HPP

//template <typename T>: This line declares a template.
//T is a placeholder for a data type.
//When you use this template to create a function,
//T will be replaced with the actual data type you want to use.
template <typename T>
void swap(T& a, T&b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
const T& min(T& a, T&b)
{
	if(a < b)
		return (a);
	return (b);
}

template <typename T>
const T& max(T& a, T&b)
{
	if(a > b)
		return (a);
	return (b);
}

#endif