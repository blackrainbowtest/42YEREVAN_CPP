#include "contact.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>

std::string Contact::_fields_name[5] =
{
	"First Name",
	"Last Name",
	"Nickname",
	"Phone Number",
	"Darkest Secret"
};

Contact::Contact()
{
}

Contact::~Contact()
{
}

bool	Contact::set_contact()
{
	for (int xi = FirstName; xi <= DarkestSecret; ++xi)
	{
		std::cout << "Please enter the " << Contact::_fields_list[xi] << ":\n>";
		while (!(std::getline(std::cin, this->_informations[xi])) || this->_informations[xi].empty())
		{
			if (std::cin.eof())
			{
				std::cout << "Note: ^D detected. Exiting phonebook..." << std::endl;
				std::exit(0);
			}
			else if (this->_informations[xi].empty())
			{
				std::cout << "Note: Empty string not allowed" << std::endl;
				std::cout << "Please enter the " << Contact::_fields_list[xi] << ":\n>";
			}

		}
	}
	std::cout << "New contact added successfully." << std::endl;
	return (true);
}

void	Contact::get_contact(int index) const
{
	std::cout << "|" << std::setw(10) << index;
	for (int xi = FirstName; xi <= NickName; ++xi)
	{
		std::cout << "|";
		if (this->_informations[xi].length() > 10)
			std::cout << this->_informations[xi].substr(0, 9) << ".";
		else
			std::cout << std::setw(10) << this->_informations[xi];
	}
	std::cout << "|" << '\n';
}
