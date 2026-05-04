#include "Harl.hpp"

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#define BLACK "\033[30m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define BG_MAGENTA "\033[45m"
#define BG_CYAN "\033[46m"
#define RESET "\033[0m"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::debug()
{
	std::cout << CYAN << "[DEBUG]\t\t" << RESET 
			  << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" 
			  << std::endl;
}

void Harl::info()
{
	std::cout << CYAN << "[INFO]\t\t" << RESET 
			  << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" 
			  << std::endl;
}

void Harl::warning()
{
	std::cout << CYAN << "[WARNING]\t" << RESET 
			  << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
			  << std::endl;
}

void Harl::error()
{
	std::cout << CYAN << "[ERROR]\t\t" << RESET 
			  << "This is unacceptable! I want to speak to the manager now." 
			  << std::endl;
}

void Harl::complain(std::string level)
{
	void (Harl::*complaintsPTRS[])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	std::string complaints[] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	int xi = 0;
	for (; xi < 4; xi++)
	{
		if (complaints[xi] == level)
			break ;
	}
	switch (xi)
	{
		case(0):
			(this->*complaintsPTRS[0])();
			// fallthrough
		case(1):
			(this->*complaintsPTRS[1])();
			// fallthrough
		case(2):
			(this->*complaintsPTRS[2])();
			// fallthrough
		case(3):
			(this->*complaintsPTRS[3])();
			break ;
	default:
		std::cout << MAGENTA << "[ Probably complaining about insignificant problems ]" 
				  << RESET << std::endl;
		break;
	}

}
