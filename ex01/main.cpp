#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

int	main(void)
{
	PhoneBook	phoneBook;
	std::string	input;

	std::cout << CYAN << "Wellcome!" << RESET << '\n';
	while (true)
	{
		phoneBook.getInstruction();
		if (!std::getline(std::cin, input))
			break ;

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
			std::cout << RED << "Exiting program." << RESET << '\n';
			break ;
		}
	}
	return (0);
}
