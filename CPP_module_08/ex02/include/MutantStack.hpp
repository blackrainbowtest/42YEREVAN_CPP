#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template <typename T>

class MutantStack : public std::stack<T>
{
	public:
		typedef std::stack<T>						stack_type;
		typedef typename stack_type::container_type	container_type;
		typedef typename container_type::iterator		iterator;

		MutantStack(void) : stack()
		{
			std::cout << "MutantStack default constructor called" << std::endl;
		}

		MutantStack(const MutantStack &src) : stack(src)
		{
			std::cout << "MutantStack copy constructor called" << std::endl;
		}

		~MutantStack(void)
		{
			std::cout << "MutantStack destructor called" << std::endl;
		}

		stack &operator=(const stack &src)
		{
			if (*this != src)
				*this = src;
			return (*this);
		}

		iterator begin(void)
		{
			return (this->c.begin());
		}

		iterator end(void)
		{
			return (this->c.end());
		}

	private:

};

#endif // MUTANTSTACK_HPP