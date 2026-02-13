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

void	PhoneBook::get_instruction(void)const
{
	std::cout << "The program only accepts ADD, SEARCH and EXIT" << "\n";
	std::cout << "ADD: save new contact." << "\n";
	std::cout << "SEARCH: display a specific contact." << "\n";
	std::cout << "EXIT: quit program and lose contacts." << "\n";
}

void	PhoneBook::addContact(void)
{

}

void	PhoneBook::searchContact(void)const
{

}
