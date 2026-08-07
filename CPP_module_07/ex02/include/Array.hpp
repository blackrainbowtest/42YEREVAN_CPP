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
        Array(): _array(NULL), _size(0)
        {
        }

        Array(unsigned int size): _array(new T[size]()), _size(size)
        {
        }

        Array(const Array &src): _array(NULL), _size(src._size)
        {
            unsigned int    i = 0;

            if (this->_size == 0)
                return ;
            this->_array = new T[this->_size];
            while (i < this->_size)
            {
                this->_array[i] = src._array[i];
                ++i;
            }
        }

        ~Array()
        {
            delete[] _array;
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
            public:
                virtual const char *what() const throw();
        };
    /** Getter - Setter */
        unsigned int size() const
        {
            return (this->_size);
        }
};

template< typename T>
const char *Array<T>::InvalidIndexException::what() const throw()
{
    return ("Error: out-of-bounds invalid index.");
}

#endif // ARRAY