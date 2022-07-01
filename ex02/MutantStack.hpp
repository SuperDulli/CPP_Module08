#ifndef MUTANT_STACK_H
#define MUTANT_STACK_H

#include <stack>
#include <deque>
#include <iterator>

template< typename T, class C = std::deque<T> >
class MutantStack : public std::stack<T, C> {

public:

	MutantStack(void): std::stack<T, C>() {}
	MutantStack(MutantStack const& other): std::stack<T, C>() {
		*this = other;
	}
	~MutantStack(void) {}

	MutantStack& operator=(MutantStack const& other) {
		std::stack<T>::operator=(other);
	}

	typename C::iterator begin(void) {
		return std::stack<T, C>::container_type.begin();
	}
};

#endif
