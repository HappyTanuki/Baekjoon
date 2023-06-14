#include "MyClass.h"

MyClass::MyClass() {
	this->number = 0;
}

MyClass::MyClass(int number) {
	setNumber(number);
}

void MyClass::setNumber(int number) {
	this->number = number;
}

int* MyClass::getFactorizdPrimeNumbers() {
	int number = this->number;
	int* output = new int[this->number + 1] { 0, };

	for (int i = 2; number != 1;) {
		if (number % i == 0) {
			output[i]++;
			number /= i;
		}
		else {
			i++;
		}
	}

	return output;
}

int MyClass::length() {
	return this->number;
}