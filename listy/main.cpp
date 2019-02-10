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

	list<int> second_list(list_of_ints);
	for (auto it = second_list.begin(); it != second_list.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << "\n";

	list<int> third_list(++second_list.begin(), second_list.end());
	for (auto it = third_list.begin(); it != third_list.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << "\n";

	list<int> fourth_list(++third_list.begin());
	for (auto it = fourth_list.begin(); it != fourth_list.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << "\n";

	system("PAUSE");

	return 0;
}