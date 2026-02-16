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

		bool	addContact(void);
		bool	searchContact(void)const;
		void	getInstruction(void)const;
		void	updateIndex(void);
		bool	showContacts(int count)const;
		int		getCount(void)const;
};
#endif // ! PHONEBOOK_HPP