/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 18:04:17 by aramarak          #+#    #+#             */
/*   Updated: 2026/10/03 18:04:19 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template <typename T>

class MutantStack : public std::stack<T>
{
	public:
		typedef std::stack<T>					stack;
		typedef typename stack::container_type	container;
		typedef typename container::iterator	iterator;

		MutantStack(void) : stack()
		{
			std::cout << "MutantStack default constructor called" << std::endl;
		}

		MutantStack(const MutantStack &src) : stack(src)
		{
			std::cout << "MutantStack copy constructor called" << std::endl;
		}

		~MutantStack(void)
		{
			std::cout << "MutantStack destructor called" << std::endl;
		}

		MutantStack &operator=(const MutantStack &src)
		{
			if (this != &src)
				stack::operator=(src);
			return (*this);
		}

		iterator begin(void)
		{
			return (this->c.begin());
		}

		iterator end(void)
		{
			return (this->c.end());
		}

	private:

};

#endif // MUTANTSTACK_HPP
