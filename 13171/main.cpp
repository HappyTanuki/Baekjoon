#include <iostream>
#include <unordered_map>
#include <cmath>

long long int modular(long long int A, long long int B, int C, std::unordered_map<int, long long>& memo) {
	std::unordered_map<int, long long>::iterator findIter = memo.find(B);

	if (B == 1) {
		return A % C;
	}
	long long mid = B / 2;

	if (findIter != memo.end()) {
		return findIter->second;
	}
	else {
		memo.insert(std::unordered_map<int, long long>::value_type(B, (modular(A, mid, C, memo) * modular(A, B - mid, C, memo)) % C));
		findIter = memo.find(B);
		return findIter->second;
	}
}

int main() {
	long long int A = 0, X = 0;
	std::unordered_map<int, long long int> memo;
	long long int result = 1;

	std::cin >> A >> X;

	int i = 0;
	while (true) {
		if (X <= 0) {
			break;
		}
		if (X & 1) {
			result = ((result % 1000000007) * modular(A, pow(2, i), 1000000007, memo)) % 1000000007;
		}

		X = X >> 1;
		i++;
	}

	std::cout << result;
}