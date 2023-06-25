#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::vector<int> permutation;
	int N = 0;

	std::cin >> N;

	for (int i = 1; i <= N; i++) {
		permutation.push_back(i);
	}

	do {
		for (int i = 0; i < N; i++) {
			std::cout << permutation[i] << ' ';
		}
		std::cout << '\n';
	} while (std::next_permutation(permutation.begin(), permutation.end()));
}