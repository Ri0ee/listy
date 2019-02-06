#include <iostream>
#include "listy.h"

int main() {
	list<int> list_of_ints;
	list_of_ints.push(1);
	list_of_ints.push_front(6);
	list_of_ints.insert(1, 10);

	for(int i = 0; i < list_of_ints.size(); i++)
		std::cout << list_of_ints[i] << " ";
	std::cout << "\n";

	system("PAUSE");
	return 0;
}