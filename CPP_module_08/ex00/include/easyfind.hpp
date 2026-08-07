/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 09:50:45 by aramarak          #+#    #+#             */
/*   Updated: 2026/07/23 10:57:10 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

template < typename T > // can define like template < class T > // too
const T &max(const T &x, const T &y)
{
    return (x > y ? x : y);
}

template < typename T >
const T &min(const T &x, const T &y)
{
    return (x < y ? x : y);
}

template < typename T >
void    swap(T &x, T &y)
{
    T temp = x;
    x = y;
    y = temp;
}

#endif // EASYFIND