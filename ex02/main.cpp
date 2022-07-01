#include <iostream>
#include <string>
#include "MutantStack.hpp"

int main(void) {

	MutantStack<int> ms;

	ms.push(1);
	ms.push(2);

	std::cout << *ms.begin() << std::endl;

	return 0;
}
