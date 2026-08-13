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

#endif // EASYFIND