#include <iostream>
#include <algorithm>
#include "Span.hpp"

char const* Span::NoSpaceLeftException::what(void) const throw() {
	return "already at maximum capacity";
}

char const* Span::NoSpanPossibleException::what(void) const throw() {
	return "too few numbers to create Span";
}

Span::Span(void): m_capacity(0) {
	this->m_numbers = std::list<int>();
}

Span::Span(unsigned int n): m_capacity(n) {
	this->m_numbers = std::list<int>();
}

Span::Span(Span const& other): m_capacity(other.m_capacity) {
	*this = other;
}

Span::~Span(void) {}

Span& Span::operator=(Span const& other) {
	if (this->m_capacity < other.m_capacity) {
		// TODO
		std::cout << "Span got truncated" << std::endl;
	}
	this->m_numbers.assign(other.m_numbers.begin(), other.m_numbers.end());
	return *this;
}

void Span::addNumber(int number) throw(Span::NoSpaceLeftException) {
	if (this->m_numbers.size() == this->m_capacity) {
		throw Span::NoSpaceLeftException();
	}
	this->m_numbers.push_back(number);
}

unsigned int Span::shortestSpan(void) const throw(Span::NoSpanPossibleException) {
	if (m_numbers.size() < 2) throw Span::NoSpanPossibleException();

	std::list<int> copy = std::list<int>(m_numbers);
	copy.sort();

	unsigned int min = std::numeric_limits<unsigned int>::max();
	std::list<int>::const_iterator it = copy.begin();
	std::list<int>::const_iterator it_next = ++copy.begin();
	while (it_next != copy.end())
	{
		unsigned int const d = getDistance(*it, *it_next);
		if (d == 0) return 0;
		if (d < min) min = d;
		++it;
		++it_next;
	}
	return min;
}

unsigned int Span::largestSpan(void) const throw(Span::NoSpanPossibleException) {
	if (m_numbers.size() < 2) throw Span::NoSpanPossibleException();

	int const min = *std::min_element(m_numbers.begin(), m_numbers.end());
	int const max = *std::max_element(m_numbers.begin(), m_numbers.end());

	// find both min and max with one call (c++11)
	// std::pair<std::list<int>::const_iterator, std::list<int>::const_iterator> result
	// 	= std::minmax_element(m_numbers.begin(), m_numbers.end());
	// int min = *result.first;
	// int max = *result.second;

	return getDistance(min, max);
}

// avoid overflow
unsigned int Span::getDistance(int const a, int const b) const {
	int const min = std::min(a, b);
	int const max = std::max(a, b);
	if (min < 0 && max >= 0)
		return static_cast<unsigned int>(-min) + static_cast<unsigned int>(max);
	return max - min;
}

