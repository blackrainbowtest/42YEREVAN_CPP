#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <exception>
#include <vector>
#include <iterator>
#include <climits>

class Span
{
	private:
		std::vector<int>	_storage;
		unsigned int		_size;

		Span();

	public:
	// Constructors
		Span(unsigned int N);
		Span(const Span &src);

	// Destructor
		~Span();

	// Overloaded Operators
		Span	&operator=(const Span &src);

	// Public Methods
		void			addNumber(int number);

		/*
		 * Adds multiple numbers from the iterator range [begin, end).
		 * The iterator 'end' itself is not included. [0,5) means 0,1,2,3,4.
		 */
		void			addNumber(std::vector<int>::iterator begin,
							std::vector<int>::iterator end);

		/*
		 * Finds the smallest difference between any two stored numbers.
		 * Throws ComparisonInvalidException if fewer than 2 numbers exist.
		 */
		unsigned int	shortestSpan() const;

		/*
		 * Finds the largest difference between any two stored numbers.
		 * Throws ComparisonInvalidException if fewer than 2 numbers exist.
		 */
		unsigned int	longestSpan() const;

	// Getter
		unsigned int	getSize() const;

	// Exceptions
		class ArrayFullException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		class ComparisonInvalidException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
};

#endif // SPAN_HPP