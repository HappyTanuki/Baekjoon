#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

int main() {
	char words[50][15] = { 0, };
	int wordSet[50] = { 0, };
	int learnedCharactor = 0;
	int wordCanRead = 0;
	int maxWordCanRead = 0;
	int N = 0, K = 0;

	std::cin >> N >> K;

	for (int i = 0; i < N; i++) {
		std::cin >> words[i];
		for (int j = 0; j < strlen(words[i]); j++) {
			wordSet[i] |= (1 << (words[i][j] - 'a'));
		}
		wordSet[i] -= (1 << ('a' - 'a'));
		wordSet[i] -= (1 << ('c' - 'a'));
		wordSet[i] -= (1 << ('i' - 'a'));
		wordSet[i] -= (1 << ('n' - 'a'));
		wordSet[i] -= (1 << ('t' - 'a'));
	}
	
	if (K >= 5) {
		std::vector<bool> combination(21, true);

		for (int i = 0; i < 21 - (K-5); i++) {
			combination[i] = false;
		}

		do {
			int j = 0;
			learnedCharactor = 0;
			learnedCharactor |= (1 << ('a' - 'a'));
			learnedCharactor |= (1 << ('c' - 'a'));
			learnedCharactor |= (1 << ('i' - 'a'));
			learnedCharactor |= (1 << ('n' - 'a'));
			learnedCharactor |= (1 << ('t' - 'a'));
			for (int i = 0; i < 21; i++) {
				if (combination[i]) {
					if (0 <= i && i <= 0) {
						j = i + 1;
					}
					else if (0 < i && i <= 5) {
						j = i + 2;
					}
					else if (5 < i && i <= 10) {
						j = i + 3;
					}
					else if (10 < i && i <= 15) {
						j = i + 4;
					}
					learnedCharactor |= (1 << j);
				}
			}

			wordCanRead = 0;
			for (int i = 0; i < N; i++) {
				if ((wordSet[i] & learnedCharactor) == wordSet[i]) {
					wordCanRead++;
				}
			}

			if (wordCanRead > maxWordCanRead) {
				maxWordCanRead = wordCanRead;
			}
		} while (std::next_permutation(combination.begin(), combination.end()));
	}

	std::cout << maxWordCanRead;
}