#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <list>
#include "displayContainer.hpp"

int main(void) {
	std::cout << "--- Test begin ---" << std::endl;
	std::list<int> mlist;

	std::cout << "isEmpty: " << mlist.empty() << std::endl;
	std::cout << "size: " << mlist.size() << std::endl;

	mlist.push_back(5);
	mlist.push_back(17);

	std::cout << mlist.back() << std::endl;

	mlist.pop_back();

	std::cout << "isEmpty: " << mlist.empty() << std::endl;
	std::cout << "size: " << mlist.size() << std::endl;

	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737);
	mlist.push_back(42);
	mlist.push_back(47);

	std::list<int> const copy(mlist);

	std::cout << "---" << std::endl;

	std::list<int>::iterator it = mlist.begin();
	std::list<int>::iterator ite = mlist.end();

	std::cout << "begin: " << *mlist.begin() << std::endl;
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		*it += 1;
		++it;
	}

	std::cout << "---" << std::endl;

	std::stack< int, std::list<int> > s(mlist);
	std::cout << "copy list to std::stack. back of list & top of stack:" << std::endl;

	std::cout << mlist.back() << std::endl;
	std::cout << s.top() << std::endl;

	std::cout << "---" << std::endl;

	std::list<int> const assign = mlist;

	std::list<int>::const_iterator it2 = copy.begin();

	++it2;
	--it2;
	displayContainer(copy);
	displayContainer(assign);

	std::cout << "-- construct list from vector --" << std::endl;

	std::vector<std::string> vec;

	vec.push_back("Pepsi");
	vec.push_back("Sunny");
	vec.push_back("Hi");
	vec.push_back("this");
	vec.push_back("is");
	vec.push_back("Brain");

	std::list<std::string> strlist(vec.begin(), vec.end());

	std::cout << "vector: " << std::endl;
	displayContainer(vec);
	std::cout << "str list: " << std::endl;
	displayContainer(strlist);

	std::list<std::string>::const_reverse_iterator
		rit = strlist.rbegin();
	std::list<std::string>::const_reverse_iterator
		rite = strlist.rend();

	std::cout << "str list (in reverse): " << std::endl;
	while (rit != rite) {
		std::cout << *rit << std::endl;
		++rit;
	}

	std::cout << "--- Test end ---" << std::endl;
	return 0;
}
