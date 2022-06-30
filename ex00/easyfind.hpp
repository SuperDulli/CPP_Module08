#ifndef EASYFIND_H
#define EASYFIND_H

#include <iterator>
#include <algorithm>

template<class T>
typename T::iterator easyfind(T& intContainer, int val) {
	return std::find(intContainer.begin(), intContainer.end(), val);
}

template<class T>
typename T::const_iterator easyfind(T const& intContainer, int val) {
	return std::find(intContainer.begin(), intContainer.end(), val);
}

#endif
