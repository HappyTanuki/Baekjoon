#include <iostream>
#include <string>
#include <cstring>
#include <stack>

int main() {
	const char* frula = "FRULA";

	std::string input;

	char* left = nullptr;
	char* leftTop = nullptr;
	std::stack<char> right;

	char bomb[36] = { 0, };
	int bombSize = 0;

	char* bombPos = nullptr;

	std::cin >> input;
	std::cin >> bomb;

	left = new char[input.length() + 2];
	leftTop = left + input.length() - 1;
	*(leftTop + 1) = '\0';

	memcpy(left, input.c_str(), (leftTop - left) + 1);

	bombSize = strlen(bomb);

	do {
		bombPos = strstr(left, bomb);
		if (bombPos != nullptr) {
			while (leftTop >= bombPos) {
				right.push(*(leftTop));
				*(leftTop--) = '\0';
			}
			for (int i = 0; i < bombSize; i++) {
				right.pop();
			}
			while (!right.empty()) {
				*(++leftTop) = right.top();
				right.pop();
			}
		}
	} while (bombPos != nullptr);
	*(++leftTop) = '\0';

	if (left > leftTop) {
		std::cout << frula;
	}
	else {
		std::cout << left;
	}
}