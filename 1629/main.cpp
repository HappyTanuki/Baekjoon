#include <iostream>
#include <unordered_map>

long long int modular(int A, int B, int C, std::unordered_map<int, long long> &memo) {
	std::unordered_map<int, long long>::iterator findIter = memo.find(B);

	if (B == 1) {
		return A % C;
	}
	int mid = B / 2;

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
	int A = 0, B = 0, C = 0;
	std::unordered_map<int, long long>memo;

	std::cin >> A >> B >> C;

	std::cout << modular(A, B, C, memo);
}