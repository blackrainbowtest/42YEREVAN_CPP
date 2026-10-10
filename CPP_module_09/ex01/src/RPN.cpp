#include "RPN.hpp"

// constructor
RPN::RPN() {}

// copy constructor
RPN::RPN(const RPN &other)
{
	this->_stack = other._stack;
}

// assignment operator
RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
		this->_stack = other._stack;
	return (*this);
}

// destructor
RPN::~RPN() {}

// Private member functions

// Public member functions
