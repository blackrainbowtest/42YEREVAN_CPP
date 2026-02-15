#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	PhoneBook;
	bool		isExit = false;
	std::string	input;

	PhoneBook.getInstruction();
	while (!isExit && std::getline(std::cin, input))
	{
		if (input.compare("ADD") == 0)
			phoneBook.addContact();
		else if (input.compare("SEARCH") == 0)
			phoneBook.searchContact();
		else if (input.compare("EXIT") == 0)
		{
			std::cout << "Exiting programm." << std::endl;
			isExit = true;
		}
		phoneBook.getInstruction();
	}
	if (!isExit)
		std::cout << "You Pressed ^D. Exiting phonebook now." << std::endl;
	return (0);
}