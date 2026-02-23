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

void	PhoneBook::getInstruction(std::ostream &out)const
{
	out << "The program only accepts " 
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

void	PhoneBook::printHeader(std::ostream &out)const
{
	out	<< "|"
		<< BLUE
		<< std::setw(10)
		<< "Index"
		<< RESET;
	out	<< "|"
		<< BLUE
		<< std::setw(10)
		<< "First Name"
		<< RESET;
	out	<< "|"
		<< BLUE
		<< std::setw(10)
		<< "Last Name"
		<< RESET;
	out	<< "|"
		<< BLUE
		<< std::setw(10)
		<< "Nickname"
		<< RESET;
	out << "|\n";
}

bool	PhoneBook::addContact(std::istream &in, std::ostream &out)
{
	if (_count >= 8)
		out << "Warning: Oldest contact will be overwritten.\n";
	if (this->_contacts[_index].set_contact(in, out))
	{
		updateIndex();
		return (true);
	}
	else
		return (false);
}

bool	PhoneBook::searchContact(std::istream &in, std::ostream &out)const
{
	int				inputIndex;
	std::string		input;

	if (_count == 0)
	{
		out << "Phone book empty, enter some data first!" << "\n";
		return (true);
	}
	printHeader(out);
	for (int xi = 0; xi < _count; ++xi)
	{
		_contacts[xi].get_contact_row(out, xi);
	}
	out << "Enter contact index (0-7 allowed)" << NLTWR;
	while (true)
	{
		if (!std::getline(in, input))
		{
			if (in.eof())
				return (false);
		}
		if (input.empty())
		{
			out << "Empty string not allowed\n>";
			continue;
		}
		else if (input.length() != 1 || !std::isdigit(static_cast<unsigned char>(input[0])))
		{
			out << "Note: Required numeric enter" << "\n";
			return (true);
		}
		inputIndex = input[0] - '0';
		if (inputIndex < 0 || inputIndex >= _count)
		{
			out << "Note: Index out of range" << "\n";
			return (true);
		}
		_contacts[inputIndex].get_contact_info(out);
		break ;
	}
	return (true);
}
