#include <iostream>

#include "MyClass.h"

int main() {
	int input;
	int* result;

	std::cin >> input;

	MyClass* myObject = new MyClass(input);

	result = myObject->getFactorizdPrimeNumbers();

	for (int i = 2; i <= myObject->length(); i++) {
		for (int j = 0; j < result[i]; j++) {
			std::cout << i << std::endl;
		}
	}

	delete[] result;
	delete myObject;
}