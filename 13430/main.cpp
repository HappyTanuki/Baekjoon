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
}

int main() {
	int k = 0, n = 0;

	std::cin >> k >> n;

	std::cout << xGCD(S(k, n), 1);
}