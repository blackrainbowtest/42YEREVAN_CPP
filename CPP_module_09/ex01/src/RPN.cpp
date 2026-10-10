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
bool RPN::isOperand(char c)
{
	return (c >= '0' && c <= '9');
}

bool RPN::isOperator(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

int RPN::calcOperation(int a, int b, char op)
{
	switch (op)
	{
		case '+':
			return (a + b);
		case '-':
			return (a - b);
		case '*':
			return (a * b);
		case '/':
			if (b == 0)
				throw std::runtime_error("Error: division by zero");
			return (a / b);
		default:
			throw std::runtime_error("Error: invalid operator");
	}
}

// Public member functions

void RPN::evaluate(const std::string &expression)
{
	// 1. Initialize variables and clear the stack
	int a;	// left operand
	int b;	// right operand
	size_t i;
	
	_stack = std::stack<int>(); // Clear the stack

	// 2. Iterate through each character in the expression
	for (i = 0; i < expression.length(); ++i)
	{
		// 3. Skip whitespace characters
		if (expression[i] == ' ')
			continue;

		// 4. If isOperand() returns true
		if (isOperand(expression[i]))
		{
			// 4.1. Convert the character to an integer
			a = expression[i] - '0';

			// 4.2. Push the integer onto the stack
			_stack.push(a);
		}

		// 5. If isOperator() returns true
		if (isOperator(expression[i]))
		{
			// 5.1. Check if the stack contains at least two operands
			if (_stack.size() < 2)
				throw std::runtime_error("Error: invalid expression");

			// 5.2. Pop the right operand (b)
			b = _stack.top();
			_stack.pop();

			// 5.3. Pop the left operand (a)
			a = _stack.top();
			_stack.pop();

			// 5.4. Calculate the result using calcOperation(a, b, op)
			

			// 5.5. Push the result back onto the stack
			_stack.push(calcOperation(a, b, expression[i]));
		}

		// 6. Throw an exception if the character is invalid
	}

	// 7. Verify that exactly one element remains in the stack

	// 8. Print the final result
}
