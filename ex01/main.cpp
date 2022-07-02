#include <cstdlib> // rand
#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>
#include "displayContainer.hpp"
#include "Color.hpp"
#include "Span.hpp"

void handleException(std::exception& e) {
	std::cerr
	<< Color::Modifier(Color::FG_RED)
	<< e.what()
	<< Color::Modifier()
	<< std::endl;
}

int main(void) {
srand(time(NULL));
{
	std::cout << "Test from the subject:" << std::endl;
	Span sp(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.largestSpan() << std::endl;
}
std::cout << std::string(80, '-') << std::endl;
{
	std::cout << "Test exceptions:" << std::endl;

	Span empty;

	try {
		empty.addNumber(42);
	} catch(std::exception& e) {
		handleException(e);
	}

	Span one(1);

	try {
		one.addNumber(42);
		one.addNumber(0);
	} catch(std::exception& e) {
		handleException(e);
	}
	try {
		std::cout << one.largestSpan() << std::endl;
		std::cout << one.shortestSpan() << std::endl;
	} catch(std::exception& e) {
		handleException(e);
	}

	std::vector<int> vec(10);
	try {
		one.addNumber(vec.begin(), vec.end());
	} catch(std::exception& e) {
		handleException(e);
	}
}
{
	std::cout << "Test with two identical numbers:" << std::endl;

	Span two(2);
	two.addNumber(42);
	two.addNumber(42);

	std::cout << two.largestSpan() << std::endl;
	std::cout << two.shortestSpan() << std::endl;
}
{
	std::cout << "Test with two numbers of same size but different sign:" << std::endl;

	Span two(2);
	two.addNumber(21);
	two.addNumber(-21);

	std::cout << two.largestSpan() << std::endl;
	std::cout << two.shortestSpan() << std::endl;
}
{
	std::cout << "Test with INT_MAX and INT_MIN:" << std::endl;

	Span two(2);
	two.addNumber(std::numeric_limits<int>::max());
	two.addNumber(std::numeric_limits<int>::min());

	std::cout << two.largestSpan() << std::endl;
	std::cout << two.shortestSpan() << std::endl;

	std::cout << std::numeric_limits<unsigned int>::max() << " <- unsigned int max" << std::endl;
}
{
	std::cout << "Test with 10000 random numbers:" << std::endl;
	std::vector<int> vec(10000);
	std::generate(vec.begin(), vec.end(), rand);
	// displayContainer(vec);

	Span large(10000);
	large.addNumber(vec.begin(), vec.end());
	std::cout << large.largestSpan() << std::endl;
	std::cout << large.shortestSpan() << std::endl;
}
{
	unsigned int const N = 1000000;
	std::cout << "Test with " << N << " random numbers:" << std::endl;
	std::vector<int> vec(N);
	std::generate(vec.begin(), vec.end(), rand);
	vec[0] *= -1; // flip the sign of the first number

	Span large(N);
	large.addNumber(vec.begin(), vec.end());
	std::cout << large.largestSpan() << std::endl;
	std::cout << large.shortestSpan() << std::endl;
}
return 0;
}
