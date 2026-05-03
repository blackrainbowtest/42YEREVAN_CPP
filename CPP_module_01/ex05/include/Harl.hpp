#ifndef HARL_HPP
# define HARL_HPP

#include <string>
#include <iostream>

class Harl
{
	public:
		// Constructors and destructor
		Harl();
		~Harl();
		// Member functions
		void complain(std::string level);
	private:
		// Helper functions for each complaint level
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
};

#endif // !HARL_HPP
