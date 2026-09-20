#include "easyfind.hpp"
#include <list>

int main()
{
	std::list<int> test;
	test.push_back(668);
	test.push_back(669);
	test.push_back(670);

	std::list<int>::const_iterator	it = test.end();

	try
	{
		it = ::easyfind(test, 668);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	if (it != test.end())
		std::cout << *it << " found" << std::endl;

	it = test.end();

	try
	{
		it = ::easyfind(test, 111);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	if (it != test.end())
		std::cout << *it << " found" << std::endl;

	return (0);
}