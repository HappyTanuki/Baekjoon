#include <iostream>
#include <stack>
#include <cmath>

int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	long long int input = 0, n = 1, powered = 0, copy = 0;
	int count = 0;
	std::stack<long long int> numbers;

	std::cin >> input;

	do {
		while (!numbers.empty()) {
			numbers.pop();
		}
		copy = input;
		n = sqrt(input - count++);
		while (copy > 0 && n > 0) {
			powered = pow(n, 2);
			if ((copy - powered) >= 0) {
				numbers.push(n);
				copy -= powered;
			}
			else {
				n--;
			}
		}
	} while (numbers.size() > 4);

	std::cout << numbers.size() << '\n';
	while (!numbers.empty()) {
		std::cout << numbers.top() << ' ';
		numbers.pop();
	}
}



