#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
	std::string	_type;

	public:
		Animal(void);
		Animal(const Animal &copy);

	// Destructor
		virtual ~Animal(void);
	
	// Operators
		Animal &operator=(const Animal &copy);
	
	// Getters
		std::string	getType(void) const;
	
	// methods
		virtual void	makeSound(void) const;
};


#endif // !ANIMAL_HPP