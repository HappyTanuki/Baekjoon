#include <iostream>

int main() {
	int length = 0, sum = 0;
	char numbers[101] = { 0, };

	std::cin >> length;
	std::cin >> numbers;

	for (int i = 0; i < length; i++) {
		sum += numbers[i] - '0';
	}

	std::cout << sum;
}