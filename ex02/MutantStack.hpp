#ifndef MUTANT_STACK_H
#define MUTANT_STACK_H

#include <stack>
#include <deque>
#include <iterator>

template< typename T, typename C = std::deque<T> >
class MutantStack : public std::stack<T, C> {

public:

	MutantStack(void): std::stack<T, C>() {}
	MutantStack(C const& container): std::stack<T, C>(container) {}
	MutantStack(MutantStack const& other): std::stack<T, C>() {
		*this = other;
	}
	~MutantStack(void) {}

	MutantStack& operator=(MutantStack const& other) {
		std::stack<T>::operator=(other);
		return *this;
	}

	// forward iterators

	typedef typename C::iterator iterator;
	typedef typename C::const_iterator const_iterator;

	iterator begin(void) {
		return std::stack<T, C>::c.begin();
	}

	const_iterator begin(void) const {
		return std::stack<T, C>::c.begin();
	}

	iterator end(void) {
		return std::stack<T, C>::c.end();
	}

	const_iterator end(void) const {
		return std::stack<T, C>::c.end();
	}

	// reverse iterators

	typedef typename C::reverse_iterator reverse_iterator;
	typedef typename C::const_reverse_iterator const_reverse_iterator;

	reverse_iterator rbegin(void) {
		return std::stack<T, C>::c.rbegin();
	}

	const_reverse_iterator rbegin(void) const {
		return std::stack<T, C>::c.rbegin();
	}

	reverse_iterator rend(void) {
		return std::stack<T, C>::c.rend();
	}

	const_reverse_iterator rend(void) const {
		return std::stack<T, C>::c.rend();
	}
};

#endif
