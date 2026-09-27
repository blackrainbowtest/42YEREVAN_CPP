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
	


	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
	return 0;
}