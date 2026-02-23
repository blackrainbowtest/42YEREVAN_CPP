#ifndef  PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class	PhoneBook
{
	private:
		Contact	_contacts[8];
		int		_index;
		int		_count;
		void	updateIndex(void);
	public:
		PhoneBook(void);
		~PhoneBook(void);

		bool	addContact(std::istream &in, std::ostream &out);
		bool	searchContact(std::istream &in, std::ostream &out)const;
		void	getInstruction(std::ostream &out)const;

};
#endif // ! PHONEBOOK_HPP
