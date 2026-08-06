/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 09:58:21 by aramarak          #+#    #+#             */
/*   Updated: 2026/08/04 10:59:45 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>

template< typename T>
class Array
{
    /** */
    private:
    T               *_array;
    unsigned int    _size;
    /** */
    public:
        Array() _size(0)
        {

        }

        Array(unsigned int size): _size(size)
        {

        }

        Array(const Array &src): _size(src._size())
        {

        }
        ~Array()
        {

        }

        Array &operator=(const Array &src)
        {

        }

        T &operator[]( unsigned int index )
        {

        }
    /** Exception */
        class	InvalidIndexException : public std::exception
        {

        }

        unsigned int size() const
        {
            
        }
};

template< typename T>
const char *Array<T>::InvalidIndexException::what() const throw()
{
    return ("Error: out-of-bounds invalid index.");
}

#endif // ARRAY