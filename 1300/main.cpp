#include <iostream>
#include <cmath>
#include <fstream>
#include <algorithm>

int decitionFunc(long Bk, long N) {
	long count = 0;
	long dividedValue = 0;

	for (long i = 1; i <= N; i++) {
		dividedValue = Bk / i;
		if (dividedValue < N) {
			count += dividedValue;
		}
		else {
			count += N;
		}
	}

	return count;
}

int parametricSearch(long start, long end, long k, long N) {
	long mid = (start + end) / 2;

	if (start >= end) {
		return end;
	}

	if (decitionFunc(mid, N) >= k) {
		return parametricSearch(start, mid, k, N);
	}
	else {
		return parametricSearch(mid + 1, end, k, N);
	}
}

int main() {
	long N = 0, k = 0;

	std::cin >> N >> k;

	std::cout << parametricSearch(1, k, k, N);
}