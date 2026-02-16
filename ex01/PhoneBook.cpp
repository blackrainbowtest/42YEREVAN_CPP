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
	std::cout << "The program only accepts ADD, SEARCH and EXIT" << "\n";
	std::cout << "\tADD:\tsave new contact." << "\n";
	std::cout << "\tSEARCH:\tdisplay a specific contact." << "\n";
	std::cout << "\tEXIT:\tquit program and lose contacts." << "\n";
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

	std::cout << "Enter contact index (0-7 allowed)" << "\n>";
	while (!(std::getline(std::cin, input)) || input.empty())
	{
		if (std::cin.eof())
		{
			std::cout << "Note: ^D detected. Exiting phonebook..." << "\n";
			return (false);
		}
		else if (input.empty())
		{
			std::cout << "Note: Empty string not allowed" << "\n";
			std::cout << "Enter contact index (0-7 allowed)" << "\n>";
			continue ;
		}
		else if (input.length() != 1 || !(isdigit(input[0])))
		{
			std::cout << "Note: Required numeric enter" << "\n";
			std::cout << "Enter contact index (0-7 allowed)" << "\n>";
			continue ;
		}
		inputIndex = input[0] - '0';
		if (inputIndex < 0 || inputIndex > _count - 1)
		{
			std::cout << "Note: Index out of range" << "\n";
			std::cout << "Enter contact index (0-7 allowed)" << "\n>";
			continue;
		}
		_contacts[inputIndex].get_contact(inputIndex);
		break ;
	}
	return (true);
}
