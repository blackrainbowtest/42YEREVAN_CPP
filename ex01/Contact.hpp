#ifndef  CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
public:
	Contact(void);
	~Contact(void);
	
	bool	set_contact();
	void	get_contact(int index)const;
	void	Contact::printContacts(int count)const;

private:
	static std::string _fields_list[5];
	enum Field {
		FirstName = 0,
		LastName = 1,
		NickName = 2,
		PhoneNumber = 3,
		DarkestSecret = 4
	};
	std::string			_informations[5]; // FIXME
};
#endif // ! CONTACT_HPP