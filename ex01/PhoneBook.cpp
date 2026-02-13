#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>

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
	if (_count < 7)
		count++;
}

bool	PhoneBook::addContact(void)
{
	if (_count < 8)
	{
		if (this->_contacts[_index].set_contact())
		{

		}
		else
			return (false)
	}
	else
	{

	}
	return (true);
}

void	PhoneBook::searchContact(void)const
{

}
