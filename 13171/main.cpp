#include <iostream>

long long int power(long long int lower, int upper) {
	long long int value = 1;

	for (int i = 0; i < upper; i++) {
		value *= lower;
	}

	return value;
}

long long int modular(long long int A, long long int B, int C) {
	if (B == 1) {
		return A % C;
	}
	if (B == 0) {
		return 1;
	}

	return (power(modular(A, B / 2, C), 2) * modular(A, B % 2, C)) % C;
}

int main() {
	long long int A = 0, X = 0;
	long long int result = 1;

	std::cin >> A >> X;

	int i = 0;
	while (true) {
		if (X <= 0) {
			break;
		}
		if (X & 1) {
			result = ((result % 1000000007) * modular(A, power(2, i), 1000000007)) % 1000000007;
		}

		X = X >> 1;
		i++;
	}

	std::cout << result;
}