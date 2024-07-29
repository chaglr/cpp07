/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhnal <muhnal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 20:51:18 by muhnal            #+#    #+#             */
/*   Updated: 2024/07/29 19:00:14 by muhnal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>

// iter template function:
// This function applies a given function to each element of an array.
//
// Parameters:
// - array: The array to be processed.
// - length: The length of the array.
// - func: The function to be applied to each element.
//
// This template function iterates over the array and applies the function to
// each element.
//

#include <cstddef>

template <typename T, typename Func>
void iter(T *array, size_t length, Func func)
{
	for (size_t i = 0; i < length; ++i)
	{
		func(array[i]);
	}
}

#endif