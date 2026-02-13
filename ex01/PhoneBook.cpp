#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>

PhoneBook::PhoneBook()
{
	this->_index = 0;
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::get_instruction(void)const
{
	std::cout << "The program only accepts ADD, SEARCH and EXIT" << std::endl;
	std::cout << "ADD: save new contact." << std::endl;
	std::cout << "SEARCH: display a specific contact." << std::endl;
	std::cout << "EXIT: quit program and lose contacts." << std::endl;
}

void	PhoneBook::set_information(void)
{

}

void	PhoneBook::get_information(void)const
{

}
