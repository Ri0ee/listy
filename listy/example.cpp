#include <iostream>
#include "listy.h"

int main() {
	list<int> list_of_ints;
	list_of_ints.push(1);
	list_of_ints.push(5);
	list_of_ints.push(10);
	list_of_ints.push(123);

	for (auto it = list_of_ints.begin(); it != list_of_ints.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << "\n";

	std::cout << list_of_ints.distance(list_of_ints.begin(), list_of_ints.find_first(10)) << "\n";

	return 0;
}