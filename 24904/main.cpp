#include <iostream>

struct Position {
	int x;
	int y;
};

void rect(bool **retVal, Position location, Position size, bool visible) {
	if (size.x > 1) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == 1 && j == 1 || visible == false) {
					rect(retVal, { location.x + size.x / 3 * i, location.y + size.y / 3 * j }, { size.x / 3 , size.y / 3 }, false);
				}
				else {
					rect(retVal, { location.x + size.x / 3 * i, location.y + size.y / 3 * j }, { size.x / 3 , size.y / 3 }, true);
				}
			}
		}
	}
	else if (visible){
		retVal[location.x][location.y] = true;
	}
	else {
		retVal[location.x][location.y] = false;
	}
}

bool **callRect(Position size) {
	bool** retValue = new bool* [size.x];
	
	for (int i = 0; i < size.x; i++) {
		retValue[i] = new bool [size.x];
	}

	rect(retValue, { 0, 0 }, { size.x , size.y }, true);

	return retValue;
}

int main() {
	int N = 0;
	bool** output;

	std::cin >> N;

	output = callRect({N, N});

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (output[i][j]) {
				std::cout << '*';
			}
			else {
				std::cout << ' ';
			}
		}
		std::cout << '\n';
	}

	for (int i = 0; i < N; i++) {
		delete[] output[i];
	}
	delete[] output;
	return 0;
}