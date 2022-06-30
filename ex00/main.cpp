#include <iostream>
#include <vector>
#include <list>
#include "displayContainer.hpp"
#include "easyfind.hpp"

// void easyfindArray(std::array<int,5> const& arr, int val) {
// 	std::cout << val << " in intArr?: "; // << std::endl;

// 	std::array<int, 5>::const_iterator it = NULL;

// 	it = easyfind(arr, val);
// 	if (it != arr.end())
//     	std::cout << "Element found in intArr: " << *it << std::endl;
//   	else
//     	std::cout << "Element not found in intArr" << std::endl;
// }

int main(void) {
	int intergers[] = {1, 2, 3, 4, 5};

	// std::vector<int> const intVec(intergers, intergers + sizeof(intergers) / sizeof(int));
	std::vector<int> intVec(2, 0); // 5 ints with value 0
	for (size_t i = 0; i < sizeof(intergers) / sizeof(int); i++)
	{
		intVec.push_back(intergers[i]);
		intVec.push_back(0);
	}
	intVec.push_back(6);
	
	testEasyfind(intVec, 3);
	testEasyfind(intVec, -3);
	testEasyfind(intVec, 42);
	testEasyfind(intVec, 0);
	testEasyfind(intVec, 6);

	std::cout << "Test with List of integers" << std::endl;

	std::list<int> intList(intVec.begin(), intVec.end());

	testEasyfind(intList, 3);
	testEasyfind(intList, -3);
	testEasyfind(intList, 42);
	testEasyfind(intList, 0);
	testEasyfind(intList, 6);
	
	return 0;
}
