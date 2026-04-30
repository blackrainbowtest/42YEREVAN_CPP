#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>

static const char* RESET   = "\033[0m";
static const char* BLUEWBG  = "\033[44m";
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

bool	Contact::set_contact(std::istream &in, std::ostream &out)
{
	for (int xi = FirstName; xi <= DarkestSecret; ++xi)
	{
		out		<< "Please enter the "
				<< BLUE << Contact::_fields_list[xi] 
				<< RESET << ':' 
				<< NLTWR;
		while (true)
		{
			if (!std::getline(in, this->_informations[xi]))
			{
				if (in.eof())
				{
					out	<< BLUEWBG << "Note:"
						<< RESET << " ^D detected. Exiting phonebook..." 
						<< '\n';
					return false;
				}
			}
			if (!this->_informations[xi].empty())
				break;

			out	<< BLUEWBG << "Note:" 
				<< RESET << " Empty string not allowed" 
				<< '\n';
			out << "Please enter the "
				<< BLUE << Contact::_fields_list[xi] 
				<< RESET << ':' 
				<< NLTWR;
		}
	}
	out	<< "New contact added successfully."
		<< '\n';
	return (true);
}

void	Contact::get_contact_row(std::ostream &out, int index) const
{
	std::string field;
	out	<< "|"
		<< std::setw(10)
		<< index;
	for (int xi = FirstName; xi <= NickName; ++xi)
	{
		field = this->_informations[xi];
		if (field.length() > 10)
    		field = field.substr(0, 9) + ".";
		out	<< "|"
			<< std::setw(10)
			<< field;
	}
	out << "|"
		<< '\n';
}

void	Contact::get_contact_info(std::ostream &out) const
{
	for (int xi = FirstName; xi <= DarkestSecret; ++xi)
	{
		out	<< xi + 1
			<< ". " << BLUE  << Contact::_fields_list[xi]
			<< ": " << RESET << this->_informations[xi] << '\n';
	}
}
