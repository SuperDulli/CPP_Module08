#ifndef DISPLAY_CONTAINER_H
#define DISPLAY_CONTAINER_H

#include <iostream>
#include "easyfind.hpp"

template<typename C>
void displayContainer(C const& container) {
	typename C::const_iterator it = container.begin();
	while (it != container.end()) {
		std::cout << *it++ << " ";
	}
}

template<typename C>
void testEasyfind(C const& container, int val) {
	std::cout << val << " in (";
	displayContainer(container);
	std::cout << ")?: " << std::endl;

	typename C::const_iterator it;

	it = easyfind(container, val);
	if (it != container.end()) {
    	std::cout << "Element found: " << *it << std::endl;
		if (++it != container.end())
			std::cout << "next element: " << *it << std::endl;
		else
			std::cout << "element was found at the back" << std::endl;
	}
  	else
    	std::cout << "Element not found." << std::endl;
}

#endif
