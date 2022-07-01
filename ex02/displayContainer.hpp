#ifndef DISPLAY_CONTAINER_H
#define DISPLAY_CONTAINER_H

#include <iostream>

template<typename C>
void displayContainer(C const& container) {
	typename C::const_iterator it = container.begin();
	while (it != container.end()) {
		std::cout << *it++ << " ";
	}
}

#endif
