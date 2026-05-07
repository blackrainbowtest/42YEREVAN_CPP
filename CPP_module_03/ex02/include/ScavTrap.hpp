#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	bool	_guard_mode;
	public:
	// Constructors
		ScavTrap();
		ScavTrap(const ScavTrap& copy);
		ScavTrap(std::string name);

	// Destructor
		~ScavTrap();
	
	// Overloaded operators
		ScavTrap& operator=(const ScavTrap& src);
	
	// Subject methods
		void	attack(const std::string &target);
		void	guardGate(void);
};

#endif // !SCAVTRAP_HPP
