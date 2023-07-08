#include <iostream>
#include <cmath>

int getWarStatus(int row, int col, char** frontLine, bool** counted, int N, int M) {
	int count = 0;
	char myTeam = frontLine[row][col];

	if (row < 0 || row > M || col < 0 || col > N) {
		return 0;
	}

	counted[row][col] = true;
	count++;
	if (frontLine[row + 1][col] == myTeam && !counted[row + 1][col]) {
		count += getWarStatus(row + 1, col, frontLine, counted, N, M);
	}
	if (frontLine[row - 1][col] == myTeam && !counted[row - 1][col]) {
		count += getWarStatus(row - 1, col, frontLine, counted, N, M);
	}
	if (frontLine[row][col + 1] == myTeam && !counted[row][col + 1]) {
		count += getWarStatus(row, col + 1, frontLine, counted, N, M);
	}
	if (frontLine[row][col - 1] == myTeam && !counted[row][col - 1]) {
		count += getWarStatus(row, col - 1, frontLine, counted, N, M);
	}

	return count;
}

int main() {
	int N = 0, M = 0;
	char** frontLine = nullptr;
	bool** counted = nullptr;
	int allyCount = 0;
	int enemyCount = 0;

	std::cin >> N >> M;

	frontLine = new char* [M];
	counted = new bool* [M];
	for (int i = 0; i < M; ++i) {
		frontLine[i] = new char[N] { 0, };
		counted[i] = new bool[N] { false, };
	}

	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			std::cin >> frontLine[i][j];
		}
	}

	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			if (!counted[i][j]) {
				if (frontLine[i][j] == 'W') {
					allyCount += pow(getWarStatus(i, j, frontLine, counted, N, M), 2);
				}
				else {
					enemyCount += pow(getWarStatus(i, j, frontLine, counted, N, M), 2);
				}
			}
		}
	}

	for (int i = 0; i < M; ++i) {
		delete[] frontLine[i];
		delete[] counted[i];
	}
	delete[] frontLine;
	delete[] counted;
}