#include <iostream>
#include "listy.h"

int main() {
	list<int> list_of_ints;
	list_of_ints.push(1);
	list_of_ints.push(5);
	list_of_ints.push(10);

	for (auto it = list_of_ints.begin(); it != list_of_ints.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << "\n";

	system("PAUSE");

	return 0;
}