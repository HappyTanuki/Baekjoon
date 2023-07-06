#include <iostream>

int bubbleSort(int *A, int N) {
	int count = 0;
	int tmp = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 1; j < N; j++) {
			if (A[j - 1] > A[j]) {
				tmp = A[j - 1];
				A[j - 1] = A[j];
				A[j] = tmp;
				count++;
			}
		}
	}

	return count;
}

int main() {
	int N = 0;

	std::cin >> N;

	int* A = new int[N];

	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}

	std::cout << bubbleSort(A, N);

	delete[] A;
}