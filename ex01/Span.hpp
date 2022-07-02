#ifndef SPAN_H
#define SPAN_H

#include <list>
#include <utility> // pair
#include <limits>

class Span {

public:

	class NoSpaceLeftException : public std::exception {
	public:
		char const* what(void) const throw();
	};
	class NoSpanPossibleException : public std::exception {
	public:
		char const* what(void) const throw();
	};

	Span(void);
	Span(unsigned int n);
	Span(Span const& other);
	~Span(void);

	Span& operator=(Span const& other);

	void addNumber(int number) throw(Span::NoSpaceLeftException);

	template<class InputIterator>
	void addNumber(InputIterator first, InputIterator last) throw(Span::NoSpaceLeftException) {
		for (; first != last ; ++first)
		{
			this->addNumber(*first);
		}
	}

	unsigned int shortestSpan(void) const throw(Span::NoSpanPossibleException);
	unsigned int largestSpan(void) const throw(Span::NoSpanPossibleException);

private:

	unsigned int const	m_capacity;
	std::list<int>		m_numbers;

	unsigned int getDistance(int const a, int const b) const;

};

#endif
