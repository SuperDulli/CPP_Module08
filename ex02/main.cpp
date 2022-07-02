#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include "displayContainer.hpp"
#include "MutantStack.hpp"

int main(void) {
	std::cout << "--- Test begin ---" << std::endl;
	MutantStack<int> mstack;

	std::cout << "isEmpty: " << mstack.empty() << std::endl;
	std::cout << "size: " << mstack.size() << std::endl;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << "isEmpty: " << mstack.empty() << std::endl;
	std::cout << "size: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(42);
	mstack.push(47);

	MutantStack<int> const copy(mstack);

	std::cout << "---" << std::endl;

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	std::cout << "begin: " << *mstack.begin() << std::endl;
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		*it += 1;
		++it;
	}

	std::cout << "---" << std::endl;

	std::stack<int> s(mstack);
	std::cout << "copy mutant stack to std::stack. top of both" << std::endl;

	std::cout << mstack.top() << std::endl;
	std::cout << s.top() << std::endl;

	std::cout << "---" << std::endl;

	MutantStack<int> const assign = mstack;

	MutantStack<int>::const_iterator it2 = copy.begin();

	++it2;
	--it2;
	displayContainer(copy);
	displayContainer(assign);

	std::cout << "-- construct stack from vector --" << std::endl;

	std::vector<std::string> vec;

	vec.push_back("Pepsi");
	vec.push_back("Sunny");
	vec.push_back("Hi");
	vec.push_back("this");
	vec.push_back("is");
	vec.push_back("Brain");

	MutantStack< std::string, std::vector<std::string> > vstack(vec);

	std::cout << "vector: " << std::endl;
	displayContainer(vec);
	std::cout << "mutant stack: " << std::endl;
	displayContainer(vstack);

	MutantStack<std::string, std::vector<std::string> >::const_reverse_iterator
		rit = vstack.rbegin();
	MutantStack<std::string, std::vector<std::string> >::const_reverse_iterator
		rite = vstack.rend();

	std::cout << "mutant stack (in reverse): " << std::endl;
	while (rit != rite) {
		std::cout << *rit << std::endl;
		++rit;
	}

	std::cout << "--- Test end ---" << std::endl;
	return 0;
}
