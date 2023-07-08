#include <iostream>

int main() {
	int N = 0, M = 0;
	char** frontLine = nullptr;

	std::cin >> N >> M;

	frontLine = new char *[M];
	for (int i = 0; i < M; ++i) {
		frontLine[i] = new char[N];
	}



	for (int i = 0; i < M; ++i) {
		delete[] frontLine[i];
	}
	delete[] frontLine;
}