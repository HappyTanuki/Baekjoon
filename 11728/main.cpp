#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main() {
	int ASize = 0, BSize = 0, i = 0;

	std::cin >> ASize >> BSize;

	int *A = new int[ASize], *B = new int[BSize];

	for (i = 0; i < ASize; i++) {
		scanf("%d", &A[i]);
	}
	for (i = 0; i < BSize; i++) {
		scanf("%d", &B[i]);
	}

	int *ATemp = A;
	int *BTemp = B;
	for (i = 0; i < ASize + BSize; i++) {
		if (ATemp >= (A + ASize)) {
			printf("%d ", *BTemp++);
			continue;
		}
		if (BTemp >= (B + BSize)) {
			printf("%d ", *ATemp++);
			continue;
		}
		if (*ATemp > *BTemp) {
			printf("%d ", *BTemp++);
		}
		else {
			printf("%d ", *ATemp++);
		}
	}

	delete[] A;
	delete[] B;
}