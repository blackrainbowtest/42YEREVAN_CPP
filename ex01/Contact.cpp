#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>

static const char* RESET   = "\033[0m";
static const char* YELLOWBG  = "\033[43m";
static const char* BLUE    = "\033[34m";
static const char* NLTWR   = "\n\033[31m>\033[0m";

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

bool	Contact::set_contact()
{
	for (int xi = FirstName; xi <= DarkestSecret; ++xi)
	{
		std::cout << "Please enter the " 
				  << Contact::_fields_list[xi]
				  << ':' << NLTWR;
		while (true)
		{
			if (!std::getline(std::cin, this->_informations[xi]))
			{
				if (std::cin.eof())
				{
					std::cout << "Note: ^D detected. Exiting phonebook..." 
							  << '\n';
					return false;
				}
			}
			if (!this->_informations[xi].empty())
				break;

			std::cout << YELLOWBG << "Note:" << RESET << " Empty string not allowed" 
					  << '\n';
			std::cout << BLUE << "Please enter the " << RESET 
					  << Contact::_fields_list[xi] 
					  << ':' << NLTWR;
		}
	}
	std::cout << "New contact added successfully."
			  << '\n';
	return (true);
}

void	Contact::get_contact_row(int index) const
{
	std::cout << "|" << std::setw(10) << index;
	for (int xi = FirstName; xi <= NickName; ++xi)
	{
		std::cout << "|";
		if (this->_informations[xi].length() > 10)
			std::cout << std::setw(10) << this->_informations[xi].substr(0, 9) << ".";
		else
			std::cout << std::setw(10) << this->_informations[xi];
	}
	std::cout << "|" << '\n';
}

void	Contact::get_contact_info(void) const
{
	for (int xi = FirstName; xi <= DarkestSecret; ++xi)
	{
		std::cout << FirstName + 1
				  << ". " << BLUE  << Contact::_fields_list[xi]
				  << ": " << RESET << this->_informations[xi] << NLTWR;
	}
}
