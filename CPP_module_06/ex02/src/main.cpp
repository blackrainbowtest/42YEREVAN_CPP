#include <cstdlib>
#include <cstdio>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include "color_palletre.hpp"

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

static Base *generate(void)
{
	switch (rand() % 3)
	{
	case 0:
		return (new A());
		break;
	case 1:
		return (new B());
		break;
	case 2:
		return (new C());
		break;
	default:
		perror("Something went wrong with the random generator");
		return (NULL);
	}
}

static void identify(Base *Test)
{
	if (dynamic_cast<A *>(Test))
	{
		std::cout << CYAN << "pointer" << RESET << " identified type is A" << std::endl;
	}
	else if (dynamic_cast<B *>(Test))
	{
		std::cout << CYAN << "pointer" << RESET << " identified type is B" << std::endl;
	}
	else if (dynamic_cast<C *>(Test))
	{
		std::cout << CYAN << "pointer" << RESET << " identified type is C" << std::endl;
	}
	else
		std::cout << "unknown type" << std::endl;
}

static void identify(Base &Test)
{
	try
	{
		(void)dynamic_cast<A &>(Test);
		std::cout << MAGENTA << "reference" << RESET << " identified type is A" << std::endl;
		return ;
	}
	catch(...)
	{}
	try
	{
		(void)dynamic_cast<B &>(Test);
		std::cout << MAGENTA << "reference" << RESET << " identified type is B" << std::endl;
		return ;
	}
	catch(...)
	{}
	try
	{
		(void)dynamic_cast<C &>(Test);
		std::cout << MAGENTA << "reference" << RESET << " identified type is C" << std::endl;
		return ;
	}
	catch(...)
	{}
	std::cout << "unknown type" << std::endl;
}


int main()
{
	srand(time(NULL));

	for (int j = 0; j < 5; j++)
	{
		Base *Test = generate();
		if (Test == NULL)
			return (EXIT_FAILURE);
		else
		{
			identify(Test);
			identify(*Test);
			delete (Test);

			std::cout << std::endl;
		}
	}

	return (EXIT_SUCCESS);
}
