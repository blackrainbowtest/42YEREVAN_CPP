#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phoneBook;
	bool		isExit = false;
	std::string	input;

	phoneBook.showContacts(phoneBook.getCount());
	phoneBook.getInstruction();
	while (!isExit && std::getline(std::cin, input))
	{
		if (input.compare("ADD") == 0)
			phoneBook.addContact();
		else if (input.compare("SEARCH") == 0)
			phoneBook.searchContact();
		else if (input.compare("EXIT") == 0)
		{
			std::cout << "Exiting program." << '\n';
			isExit = true;
		}
		phoneBook.showContacts(phoneBook.getCount());
		phoneBook.getInstruction();
	}
	if (!isExit)
		std::cout << "You Pressed ^D. Exiting phoneBook now." << std::endl;
	return (0);
}