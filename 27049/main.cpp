#include <iostream>

int main() {
	std::string input;
	int sum = 0;
	int pos = 0;

	std::cin >> input;

	for (int i = 0; i < 10; i++) {
		if (input[i] != '?') {
			if (input[i] == 'X') {
				sum += 10;
			}
			else {
				sum += (input[i] - '0') * (10 - i);
			}
		}
		else {
			pos = i;
		}
	}
	for (int i = 0; i <= 10; i++) {
		sum += i * (10 - pos);
		if (sum % 11 == 0) {
			if (i == 10) {
				if (pos == 9) {
					std::cout << 'X';
				}
				else {
					break;
				}
			}
			else {
				std::cout << i;
			}
			return 0;
		}
		sum -= i * (10 - pos);
	}

	std::cout << -1;
}