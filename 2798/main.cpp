#include <iostream>

int getMaxCardSum(int cards[100], int N, int targetNumber) {
	int maxCardSum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			for (int k = j+1; k < N; k++) {
				if (cards[i] + cards[j] + cards[k] <= targetNumber && (cards[i] + cards[j] + cards[k]) > maxCardSum) {
					maxCardSum = cards[i] + cards[j] + cards[k];
				}
			}
		}
	}

	return maxCardSum;
}

int main() {
	int N = 0, M = 0;
	int inputCards[100] = { 0, };

	std::cin >> N;
	std::cin >> M;

	for (int i = 0; i < N; i++) {
		std::cin >> inputCards[i];
	}

	std::cout << getMaxCardSum(inputCards, N, M);
}