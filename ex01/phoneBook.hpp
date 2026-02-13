#ifndef  PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>

class PhoneBook
{
	private:
		Contact	_contacts[8];
		int		_index;
		bool	_isFull;
	public:
		PhoneBook(void);
		~PhoneBook(void);

		void	set_information(void);
		void	get_information(void)const;
		void	get_instruction(void);
};
#endif // ! PHONEBOOK_HPP