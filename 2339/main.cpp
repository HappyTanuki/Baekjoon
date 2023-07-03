#include <iostream>

enum class SliceDirection {
	NON_DIRECTION,
	HORIZONTAL,
	VIRTICAL
};

struct Position {
	int y;
	int x;
};

int countGems(int** tablit, Position topLeft, Position bottomRight) {
	int count = 0;

	for (int i = topLeft.y; i <= bottomRight.y; i++) {
		for (int j = topLeft.x; j <= bottomRight.x; j++) {
			if (tablit[i][j] == 2) {
				count++;
			}
		}
	}

	return count;
}

int countImpurities(int** tablit, Position topLeft, Position bottomRight) {
	int count = 0;

	for (int i = topLeft.y; i <= bottomRight.y; i++) {
		for (int j = topLeft.x; j <= bottomRight.x; j++) {
			if (tablit[i][j] == 1) {
				count++;
			}
		}
	}

	return count;
}

bool sliceCounter(SliceDirection direction, Position topLeft, Position bottomRight, int slicePos, int impuritiesCount) {
	static int horizontalSliceCount[20] = { 0, };
	static int virticalSliceCount[20] = { 0, };

	switch (direction) {
	case SliceDirection::NON_DIRECTION:
		break;
	case SliceDirection::HORIZONTAL:
		if (impuritiesCount > 1) {
			if (horizontalSliceCount[slicePos] == 1) {
				return false;
			}
		}
		else {
			return true;
		}
		horizontalSliceCount[slicePos] = 1;
		return true;
	case SliceDirection::VIRTICAL:
		if (impuritiesCount > 1) {
			if (virticalSliceCount[slicePos] == 1) {
				return false;
			}
		}
		else {
			return true;
		}
		virticalSliceCount[slicePos] = 1;
		return true;
	}

}

bool isItSliceAble(int** tablit, SliceDirection direction, Position topLeft, Position bottomRight, int slicePos) {
	int upCount = 0, downCount = 0;
	int impuritiesCount = 0;

	switch (direction) {
	case SliceDirection::NON_DIRECTION:
		return false;
		break;
	case SliceDirection::HORIZONTAL:
		if ((countGems(tablit, { slicePos, topLeft.x }, { slicePos, bottomRight.x }) != 0)) {
			return false;
		}
		impuritiesCount = countImpurities(tablit, { slicePos, topLeft.x }, { slicePos, bottomRight.x });
		break;
	case SliceDirection::VIRTICAL:
		if ((countGems(tablit, { topLeft.y, slicePos }, { bottomRight.y, slicePos }) != 0)) {
			return false;
		}
		impuritiesCount = countImpurities(tablit, { topLeft.y, slicePos }, { bottomRight.y, slicePos });
		break;
	}

	if (!sliceCounter(direction, topLeft, bottomRight, slicePos, impuritiesCount)) {
		return false;
	}

	return true;
}

int slice(int** tablit, Position topLeft, Position bottomRight, SliceDirection lastSlicedDirection) {
	int methodCount = 0;

	switch (lastSlicedDirection) {
	case SliceDirection::NON_DIRECTION:
		for (int i = topLeft.y; i <= bottomRight.y; i++) {
			for (int j = topLeft.x; j <= bottomRight.x; j++) {
				if (tablit[i][j] == 1) {
					if (isItSliceAble(tablit, SliceDirection::HORIZONTAL, topLeft, bottomRight, i)) {
						methodCount += (slice(tablit, topLeft, { (i - 1), bottomRight.x }, SliceDirection::HORIZONTAL) *
										slice(tablit, { (i + 1), topLeft.x }, bottomRight, SliceDirection::HORIZONTAL));
					}
					if (isItSliceAble(tablit, SliceDirection::VIRTICAL, topLeft, bottomRight, j)) {
						methodCount += (slice(tablit, topLeft, { bottomRight.y, (j - 1) }, SliceDirection::VIRTICAL) *
										slice(tablit, { topLeft.y, (j + 1) }, bottomRight, SliceDirection::VIRTICAL));
					}
				}
			}

		}
		if (methodCount > 0) {
			return methodCount;
		}
		else {
			return 0;
		}
		break;
	case SliceDirection::HORIZONTAL:
		for (int i = topLeft.y; i <= bottomRight.y; i++) {
			for (int j = topLeft.x; j <= bottomRight.x; j++) {
				if (tablit[i][j] == 1) {
					if (isItSliceAble(tablit, SliceDirection::VIRTICAL, topLeft, bottomRight, j)) {
						methodCount += (slice(tablit, topLeft, { bottomRight.y, (j - 1) }, SliceDirection::VIRTICAL) *
										slice(tablit, { topLeft.y, (j + 1) }, bottomRight, SliceDirection::VIRTICAL));
					}
				}
			}
		}
		break;
	case SliceDirection::VIRTICAL:
		for (int i = topLeft.y; i <= bottomRight.y; i++) {
			for (int j = topLeft.x; j <= bottomRight.x; j++) {
				if (tablit[i][j] == 1) {
					if (isItSliceAble(tablit, SliceDirection::HORIZONTAL, topLeft, bottomRight, i)) {
						methodCount += (slice(tablit, topLeft, { (i - 1), bottomRight.x }, SliceDirection::HORIZONTAL) *
										slice(tablit, { (i + 1), topLeft.x }, bottomRight, SliceDirection::HORIZONTAL));
					}
				}
			}
		}
		break;
	}
	if (countGems(tablit, topLeft, bottomRight) != 1 && methodCount == 0) {
		return 0;
	}
	else {
		if (methodCount == 0) {
			return 1;
		}
		else {
			return methodCount;
		}
	}
}

int main() {
	int** tablit;
	int N = 0;
	int methodCount = 0;

	std::cin >> N;

	tablit = new int* [N];
	for (int i = 0; i < N; i++) {
		tablit[i] = new int[N];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cin >> tablit[i][j];
		}
	}

	methodCount = slice(tablit, { 0, 0 }, { (N - 1), (N - 1) }, SliceDirection::NON_DIRECTION);

	if (methodCount > 0) {
		std::cout << methodCount;
	}
	else {
		std::cout << -1;
	}
}