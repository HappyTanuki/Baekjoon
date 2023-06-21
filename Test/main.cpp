#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <stack>
#include <cmath>

int getDecompositSum(int number) {
	int numberSum = number;

	while (number != 0) {
		numberSum += number % 10;
		number /= 10;
	}

	return numberSum;
}

int main() {
	std::ofstream file;
	file.open("out.txt");

	int* numbers = new int[1000001];

	for (int i = 1; i < 1000001; i++) {
		numbers[i] = getDecompositSum(i);
	}

	file << "i : number" << '\n';
	for (int i = 1; i < 1000001; i++) {
		file << "i : " << i << ' ' << numbers[i] << '\n';
	}

	file << "sorted numbers" << '\n';
	std::sort(numbers, numbers + 1000001);
	for (int i = 1; i < 1000001; i++) {
		file << numbers[i] << '\n';
	}

	delete[] numbers;
}