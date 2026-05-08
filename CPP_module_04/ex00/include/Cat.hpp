#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat: public Animal
{
	public:
	// Constructor
		Cat();
		Cat(const Cat &copy);
	// Destructor
		~Cat();
	
};

#endif // !CAT_HPP