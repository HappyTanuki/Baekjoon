#include <iostream>
#include <algorithm>

int main() {
	int ASize = 0, BSize = 0, input = 0, i = 0;
	int BMinusA = 0, AMinusB = 0;

	std::cin >> ASize >> BSize;

	int *A = new int[ASize], *B = new int[BSize];

	for (i = 0; i < ASize; i++) {
		std::cin >> input;
		A[i] = input;
	}
	for (i = 0; i < BSize; i++) {
		std::cin >> input;
		B[i] = input;
	}

	std::sort(A, A + ASize);
	std::sort(B, B + BSize);
	
	AMinusB = ASize;
	for (i = 0; i < BSize; i++) {
		if (std::binary_search(A, A + ASize, B[i])) {
			AMinusB--;
		}
	}
	BMinusA = BSize;
	for (i = 0; i < ASize; i++) {
		if (std::binary_search(B, B + BSize, A[i])) {
			BMinusA--;
		}
	}
	std::cout << AMinusB + BMinusA;

	delete[] A;
	delete[] B;
}