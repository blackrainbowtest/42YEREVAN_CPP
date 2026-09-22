#include "Span.hpp"

// Constructors
Span::Span(unsigned int N) : _size(N) 
{
	std::cout << "Span Constructor for size of " << N << " called" << std::endl;
	this->_storage.reserve(this->_size);
}

Span::Span(const Span &src) : _storage(src._storage), _size(src._size) 
{
	std::cout << "Span Copy Constructor called" << std::endl;
	// *this = src; // unnecessary: members are already copied by the initializer list
}

// Destructor
Span::~Span() {
	std::cout << "Span Deconstructor called" << std::endl;
}

// Overloaded Operators
Span	&Span::operator=(const Span &src)
{
	std::cout << "Span Assignation operator called" << std::endl;

	if (this == &src)
		return *this;

	this->_storage = src._storage;
	this->_size = src._size;

	return *this;
}

// Public Methods

void	Span::addNumber(int number)
{
	if (this->_storage.size() >= this->_size)
		throw Span::ArrayFullException();

	this->_storage.push_back(number);
}

/*
 * Adds all numbers from the iterator range [begin, end).
 * std::distance() returns the number of elements in the range.
 * If the entire range does not fit into Span, an exception is thrown.
 */
void	Span::addNumber(std::vector<int>::iterator begin,
					std::vector<int>::iterator end)
{
	unsigned int	range;

	range = static_cast<unsigned int>(std::distance(begin, end));
	if (this->_storage.size() + range > this->_size)
		throw Span::ArrayFullException();
	this->_storage.insert(this->_storage.end(), begin, end);
}

/*
 * Finds the smallest difference between any two stored numbers.
 * At least two numbers are required.
 */
unsigned int	Span::shortestSpan() const
{
	if (this->_storage.size() < 2)
		throw Span::ComparisonInvalidException();
	
	std::vector<int>	sorted(this->_storage);
	std::sort(sorted.begin(), sorted.end());
	unsigned int	shortest = static_cast<unsigned int>(sorted[1] - sorted[0]);
	for (size_t i = 0; i < sorted.size() - 1; ++i)
	{
		unsigned int	diff = static_cast<unsigned int>(sorted[i + 1] - sorted[i]);
		if (diff < shortest)
			shortest = diff;
	}
	return (shortest);
}

/*
 * Finds the largest difference between any two stored numbers.
 * At least two numbers are required.
 */
unsigned int	Span::longestSpan() const
{
	// ...
}

// Getter
unsigned int	Span::getSize() const
{
	return (this->_size);
}

// Exceptions
const char	*Span::ArrayFullException::what() const throw()
{
	return ("Error: Span is full");
}

const char	*Span::ComparisonInvalidException::what() const throw()
{
	return ("Error: at least two numbers are required");
}