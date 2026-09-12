/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 15:25:11 by aramarak          #+#    #+#             */
/*   Updated: 2026/05/25 09:28:41 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib>
#include <cstdio>

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
		std::cout << "identified type is A" << std::endl;
	}
	else if (dynamic_cast<B *>(Test))
	{
		std::cout << "identified type is B" << std::endl;
	}
	else if (dynamic_cast<C *>(test))
	{
		std::cout << "identified type is C" << std::endl;
	}
	else
		std::cout << "unknown type" << std::endl;
}

static int i = 0;
static std::string classes[] = {"A", "B", "C"};

static void identify(Base &Test)
{
	
	
	//TODO: Use dynamic_cast to identify the type of the object
}


int main()
{
	srand(time(NULL));
	for (int j = 0; j < 5; j++)
	{
		Base *Test = generate();
		if (Test == NULL)
			return (1);
		else
		{
			identify(Test);
			identify(*Test);
			delete (Test);

			std::cout << std::endl;
		}
	}
	return (0);
}
