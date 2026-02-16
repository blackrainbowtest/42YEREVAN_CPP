#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>

std::string Contact::_fields_list[5] =
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

void	Contact::printContacts(int count)const
{
	std::cout << "|" << std::setw(10) << "N";
	for (int xi = FirstName; xi < PhoneNumber; ++xi)
	{
		std::cout << "|" << std::setw(10) << Contact::_fields_list[xi];
	}
	std::cout << "|" << '\n';
	for (int xi = 0; xi < count; ++xi)
	{
		get_contact(xi);
	}
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
				std::cout << "Note: ^D detected. Exiting phonebook..." << '\n';
				return (false);
			}
			else if (this->_informations[xi].empty())
			{
				std::cout << "Note: Empty string not allowed" << '\n';
				std::cout << "Please enter the " << Contact::_fields_list[xi] << ":\n>";
			}

		}
	}
	std::cout << "New contact added successfully." << '\n';
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
