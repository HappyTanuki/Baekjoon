#include <iostream>
#include <algorithm>

int binarySearch(int* array, int length, int value) {
	int end = length, start = 0, mid = 0;

	while (end - start >= 0) {
		mid = (start + end) / 2;

		if (array[mid] == value) {
			return mid;
		}
		else if (array[mid] > value) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	return false;
}

int main() {
	int ASize = 0, BSize = 0, input, i = 0;
	int BMinusA = 0, AMinusB = 0;

	std::cin >> ASize >> BSize;

	std::unique_ptr<int[]> A = std::make_unique<int[]>(ASize);
	std::unique_ptr<int[]> B = std::make_unique<int[]>(BSize);

	for (i = 0; i < ASize; i++) {
		std::cin >> input;
		A[i] = input;
	}
	for (i = 0; i < BSize; i++) {
		std::cin >> input;
		B[i] = input;
	}

	std::sort(A.get(), A.get() + ASize);
	std::sort(B.get(), B.get() + BSize);
	
	AMinusB = ASize;
	for (i = 0; i < BSize; i++) {
		if (std::binary_search(A.get(), A.get() + ASize, B[i])) {
			AMinusB--;
		}
	}
	BMinusA = BSize;
	for (i = 0; i < ASize; i++) {
		if (std::binary_search(B.get(), B.get() + BSize, A[i])) {
			BMinusA--;
		}
	}
	std::cout << AMinusB + BMinusA;
}