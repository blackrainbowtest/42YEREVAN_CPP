#include <Contact.hpp>

std::string Contact::_fields_name[5] =
{
	"First Name",
	"Last Name",
	"Nickname",
	"Phone Number",
	"Darkest Secret"
};

Contact::Contact()
{
	int i = FirstName;
	while (i <= DarkestSecret)
	{
		this->_informations[i] = std::string();
		i++;
	}
}

Contact::~Contact()
{
}

bool	Contact::set_contact()
{
	int	i;

	i = FirstName;
	while (i <= DarkestSecret)
	{
		std::count << "Enter " << Contact::
		i++;
	}
	std::cout << "New contact added successfully." << std::endl;
	return (true);
}

void	Contact::get_contact(int index) const
{

}
