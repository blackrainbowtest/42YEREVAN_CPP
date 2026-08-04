/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 09:58:21 by aramarak          #+#    #+#             */
/*   Updated: 2026/08/04 10:59:45 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <string>

template <typename T>
void	iter(T *array, size_t length, void (*function)(T &))
{
	size_t	i;

	i = 0;
	while (i < length)
	{
		function(array[i]);
		i++;
	}
}

template <typename T>
void	iter(const T *array, size_t length, void (*function)(const T &))
{
	size_t	i;

	i = 0;
	while (i < length)
	{
		function(array[i]);
		i++;
	}
}

#endif // ITER