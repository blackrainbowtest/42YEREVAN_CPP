#ifndef  PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class	PhoneBook
{
	private:
		Contact	_contacts[8];
		int		_index;
		int		_count;
	public:
		PhoneBook(void);
		~PhoneBook(void);

		void	addContact(void);
		void	searchContact(void)const;
		void	get_instruction(void)const;
};
#endif // ! PHONEBOOK_HPP