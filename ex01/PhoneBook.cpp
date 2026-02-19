#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cctype>

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
	std::cout << "The program only accepts ADD, SEARCH and EXIT" << "\n>";
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
		else if (input.length() != 1 || !std::isdigit(input[0]))
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
		_contacts[inputIndex].get_contact(inputIndex);
		break ;
	}
	return (true);
}
