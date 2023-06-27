#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N = 0, M = 0, givenCard = 0;
	bool* myCard = new bool[20000001] {false};

	std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::cin >> givenCard;
		myCard[givenCard + 10000000] = true;
	}

	std::cin >> M;
	for (int i = 0; i < M; i++) {
		std::cin >> givenCard;
		if (myCard[givenCard + 10000000] == true) {
			std::cout << 1 << ' ';
		}
		else {
			std::cout << 0 << ' ';
		}
	}

	delete[] myCard;
}