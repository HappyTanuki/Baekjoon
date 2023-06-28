#include <iostream>

bool decisionFunction(unsigned int length, int* cables, int cablesQuentity, int requiredQuentity){
	int sum = 0;
	
	for (int i = 0; i < cablesQuentity; i++) {
		sum += cables[i] / length;
	}

	if (sum >= requiredQuentity) {
		return true;
	}
	else {
		return false;
	}
}

int parametricSearch(unsigned int start, unsigned int end, int* cables, int cablesQuentity, int requiredQuentity, int resultLength=0) {
	int mid = (start + end) / 2;

	if (start > end) {
		return resultLength;
	}

	if (decisionFunction(mid, cables, cablesQuentity, requiredQuentity)) {
		return parametricSearch(mid + 1, end, cables, cablesQuentity, requiredQuentity, mid);
	}
	else {
		return parametricSearch(start, mid - 1, cables, cablesQuentity, requiredQuentity, resultLength);
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int K = 0, N = 0, max = 0;
	int* cables;

	std::cin >> K >> N;
	cables = new int[K];

	for (int i = 0; i < K; i++) {
		std::cin >> cables[i];
		if (cables[i] > max) {
			max = cables[i];
		}
	}

	std::cout << parametricSearch(1, max, cables, K, N);

	delete[] cables;
}