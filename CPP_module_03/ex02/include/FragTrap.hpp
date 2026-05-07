#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	public:
	// Constructors
		FragTrap();
		FragTrap(const FragTrap& copy);
		FragTrap(std::string name);

	// Destructor
		~FragTrap();
	
	// Overloaded operators
		FragTrap& operator=(const FragTrap& src);
	
	// Subject methods
		void	highFivesGuys(void);
};

#endif // !FRAGTRAP_HPP