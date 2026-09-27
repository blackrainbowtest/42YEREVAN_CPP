#include "MutantStack.hpp"

int main()
{
	MutantStack<std::string> mstack_string;
	mstack_string.push("Hello");
	mstack_string.push("World");
	mstack_string.pop();
	mstack_string.push("C++");
	mstack_string.push("MutantStack");

	// creation int stack
	MutantStack<int> mstack_int;
	mstack_int.push(42);
	mstack_int.push(21);
	mstack_int.push(84);
	mstack_int.pop();
	mstack_int.push(168);
	mstack_int.push(336);

	std::cout << std::endl;
	


	return 0;
}