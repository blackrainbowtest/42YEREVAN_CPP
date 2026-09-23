#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iterator>
# include <iostream>
# include <exception>

# define BLACK		"\033[30m"
# define GREEN		"\033[32m"
# define BLUE		"\033[34m"
# define RED		"\033[31m"
# define YELLOW		"\033[33m"
# define MAGENTA	"\033[35m"
# define CYAN		"\033[36m"

# define BG_RED		"\033[41m"
# define BG_YELLOW	"\033[43m"
# define BG_MAGENTA	"\033[45m"
# define BG_CYAN	"\033[46m"

#define RESET		"\033[0m"

class NotFoundException: public std::exception
{
    public:
        virtual const char *what() const throw()
        {
            return ("Not found");
        }
};

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
    typename T::iterator	iter;
	iter = std::find(container.begin(), container.end(), value);
	if (iter == container.end())
	{
		throw (NotFoundException());
	}
	return (iter);
}

#endif // EASYFIND