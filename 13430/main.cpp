#include <iostream>

long long S(int k, int n) {
	long long sum = 0;

	if (k == 0) {
		return n;
	}
	for (int i = 1; i <= n; i++) {
		sum += S(k-1, i);
	}

	return sum;
}

long long xGCD(long long r1, long long r2, int s1 = 1, int s2 = 0) {
	long long q = 0;

	if (r2 == 0) {
		return s1;
	}
	
	q = r1 / r2;
	return xGCD(r2, r1 - q * r2, s2, s1 - q * s2);
	// S(k, n) mod 1000000007 = r
	// S(k, n)*Q + r = 1000000007
	// x = r/1000000007, y = Q/1000000007
	// x + S(k, n)y = 1 = gcd(S(k, n), 1)
}

int main() {
	int k = 0, n = 0;

	std::cin >> k >> n;

	std::cout << xGCD(S(k, n), 1);
}

/*
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
*/