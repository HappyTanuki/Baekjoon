#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <stack>
#include <cmath>

void getPrimeNum(std::vector<int> &primeNumbers) {
	int i, j;
	int root;
	for (i = 1000; i < 10000; i++) {
		root = sqrt(i);
		for (j = root; j > 1; --j) {
			if (i % j == 0) {
				break;
			}
		}
		if (j == 1) {
			primeNumbers.push_back(i);
		}
	}
}

int main() {
	std::ofstream file;
	int cnt = 0;
	file.open("out.txt");

	std::vector<int> primeNumbers;

	getPrimeNum(primeNumbers);

	file << "int primeNumbers[] = { ";
	for (auto iter = primeNumbers.begin(); iter != primeNumbers.end(); ++iter) {
		cnt++;
		file << *iter << ", ";
		if (cnt % 25 == 0) {
			file << "\n\t\t\t\t\t   ";
		}
	}
	file << " };";
}