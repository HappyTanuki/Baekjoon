#include <iostream>

void track(char (*words)[2][15], char charactor, int K, int depth, int count, int& max) {
	bool found = false;

	if (max < count) {
		max = count;
	}

	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 15; j++) {
			if (words[i][0][j] == charactor) {
				words[i][1][j] = 1;
			}
		}
		for (int j = 0; j < 15; j++) {
			if (words[i][1][j] == 0) {
				found = false;
				break;
			}
		}
		if (found) {
			count++;
		}
		if (depth < K) {
			for (int i = charactor - 'a'; i < 26; i++) {
				track(words, charactor + 1, K, depth + 1, count, max);
			}
		}
		if (found) {
			count--;
		}
		for (int j = 0; j < 15; j++) {
			if (words[i][0][j] == charactor) {
				words[i][1][j] = 0;
			}
		}
	}
}

int callTrack(char(*words)[2][15], int K) {
	int max = 0;
	track(words, 'a', K, 0, 0, max);

	return max;
}

int main() {
	char words[50][2][15] = {0,};
	char taughtChar[26] = { 0, };
	int N = 0, K = 0;

	std::cin >> N >> K;

	if (K < 5) {
		std::cout << 0;
	}

	for (int i = 0; i < N; ++i) {
		std::cin >> words[i][0];
	}

	std::cout << callTrack(words, K);
}