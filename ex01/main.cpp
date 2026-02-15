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

	}
	if (!isExit)
		std::cout << "Exiting programm." << std::endl;
	return (0);
}