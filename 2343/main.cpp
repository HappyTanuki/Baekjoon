#include <iostream>

int decisionFunc(int length, int* lectures, int lecturesSum, int N, int M) {
	int max = 0, sum = 0;

	if (lecturesSum > length * M) {
		return -1;
	}

	int j = 0;
	for (int i = 0; i < M; i++) {
		sum = 0;
		for (j = j; j <= N; j++) {
			if (j >= N) {
				break;
			}
			if (sum + lectures[j] <= length) {
				sum += lectures[j];
			}
			else {
				break;
			}
		}
		if (max < sum) {
			max = sum;
		}
	}

	if (j < N) {
		return -1;
	}
	else {
		return max;
	}
}

int setLength (int start, int end, int *lectures, int lecturesSum, int N, int M, int &min) {
	int mid = (start + end) / 2;

	if (start > end) {
		return 0;
	}

	int returnValue = decisionFunc(mid, lectures, lecturesSum, N, M);

	if (returnValue != -1) {
		if (returnValue < min) {
			min = returnValue;
		}
		return setLength(start, mid - 1, lectures, lecturesSum, N, M, min);
	}
	else {
		return setLength(mid + 1, end, lectures, lecturesSum, N, M, min);
	}
}

int getMinLength(int* lectures, int N, int M) {
	int min = 10000 * N, sum = 0;

	for (int i = 0; i < N; i++) {
		sum += lectures[i];
	}

	setLength(0, sum, lectures, sum, N, M, min);

	return min;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N = 0, M = 0;

	std::cin >> N >> M;

	int* lectures = new int[N];

	for (int i = 0; i < N; i++) {
		std::cin >> lectures[i];
	}

	std::cout << getMinLength(lectures, N, M);

	delete[] lectures;
}