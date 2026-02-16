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
			PhoneBook.addContact();
		else if (input.compare("SEARCH") == 0)
			PhoneBook.searchContact();
		else if (input.compare("EXIT") == 0)
		{
			std::cout << "Exiting programm." << std::endl;
			isExit = true;
		}
		PhoneBook.getInstruction();
	}
	if (!isExit)
		std::cout << "You Pressed ^D. Exiting PhoneBook now." << std::endl;
	return (0);
}