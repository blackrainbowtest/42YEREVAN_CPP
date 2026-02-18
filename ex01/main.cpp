#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

int	main(void)
{
	PhoneBook	phoneBook;
	bool		isExit = false;
	std::string	input;

	phoneBook.getInstruction();
	while (!isExit && std::getline(std::cin, input))
	{
		if (input.compare("ADD") == 0)
		{
			if (!phoneBook.addContact())
				break ;
		}
		else if (input.compare("SEARCH") == 0)
		{
			if (!phoneBook.searchContact())
				break ;
		}
		else if (input.compare("EXIT") == 0)
		{
			std::cout << "Exiting program." << '\n';
			isExit = true;
		}
		phoneBook.getInstruction();
	}
	if (!isExit)
		std::cout << "You Pressed ^D. Exiting phoneBook now." << std::endl;
	return (0);
}
