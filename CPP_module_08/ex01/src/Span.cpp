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

void	Span::addNumber(std::vector<int>::iterator begin,
					std::vector<int>::iterator end)
{
	if (this->_storage.size() + std::distance(begin, end) > this->_size)
		throw Span::ArrayFullException();

	this->_storage.insert(this->_storage.end(), begin, end);
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