#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cctype>

static const char* RESET   = "\033[0m";
// static const char* YELLOWBG  = "\033[43m";
static const char* BLUE    = "\033[34m";
static const char* NLTWR   = "\n\033[31m>\033[0m";

PhoneBook::PhoneBook()
{
	_index = 0;
	_count = 0;
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::getInstruction(void)const
{
	std::cout 	<< "The program only accepts " 
				<< BLUE << "ADD" << RESET << ", "
				<< BLUE << "SEARCH" << RESET << " and "
				<< BLUE << "EXIT" << NLTWR;
}

void	PhoneBook::updateIndex(void)
{
	_index = (_index + 1) % 8;
	if (_count < 8)
		_count++;
}

bool	PhoneBook::addContact(void)
{
	if (_count >= 8)
		std::cout << "Warning: Oldest contact will be overwritten.\n";
	if (this->_contacts[_index].set_contact())
	{
		updateIndex();
		return (true);
	}
	else
		return (false);
}

bool	PhoneBook::searchContact(void)const
{
	int				inputIndex;
	std::string		input;

	if (_count == 0)
	{
		std::cout << "Phone book empty, enter some data first!" << "\n";
		return (true);
	}

	for (int xi = 0; xi < _count; ++xi)
	{
		_contacts[xi].get_contact_row(xi);
	}
	std::cout << "Enter contact index (0-7 allowed)" << "\n>";
	while (true)
	{
		if (!std::getline(std::cin, input))
		{
			if (std::cin.eof())
				return (false);
		}
		if (input.empty())
		{
			std::cout << "Empty string not allowed\n>";
			continue;
		}
		else if (input.length() != 1 || !std::isdigit(static_cast<unsigned char>(input[0])))
		{
			std::cout << "Note: Required numeric enter" << "\n";
			return (true);
		}
		inputIndex = input[0] - '0';
		if (inputIndex < 0 || inputIndex >= _count)
		{
			std::cout << "Note: Index out of range" << "\n";
			return (true);
		}
		_contacts[inputIndex].get_contact_row(inputIndex);
		break ;
	}
	return (true);
}
