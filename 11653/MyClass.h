#pragma once
#include <vector>
#include <cmath>

class MyClass {
public:
	MyClass();
	MyClass(int number);

	void setNumber(int number);
	int* getFactorizdPrimeNumbers();
	int length();

private:
	int number;
};