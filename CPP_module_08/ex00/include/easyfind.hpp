#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iterator>
# include <iostream>
# include <exception>

class NotFoundException: public std::exception
{
    public:
        virtual const char *what() const throw()
        {
            return ("Not found");
        }
}

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
    return (std::find(container.begin(), container.end(), value));
}

#endif // EASYFIND