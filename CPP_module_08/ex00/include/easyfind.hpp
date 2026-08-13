/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 14:42:04 by aramarak          #+#    #+#             */
/*   Updated: 2026/08/13 17:05:42 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iterator>
# include <iostream>
# include <exception>

class NotFoundException: public std::exception
{
    public:
        virtual const char *what() const throw()
        {
            return ("Not found");
        }
}

template < typename T> // can define like template < class T > // too
const T &max(const T &x, const T &y)
{
    return (x > y ? x : y);
}

template < typename T>
const T &min(const T &x, const T &y)
{
    return (x < y ? x : y);
}

template < typename T>
void    swap(T &x, T &y)
{
    T temp = x;
    x = y;
    y = temp;
}

#endif // EASYFIND