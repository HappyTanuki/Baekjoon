#include <iostream>
#include <stack>

int popStackNumbers(std::stack<int>& stack);

int main() {
	std::stack<int> stack;
	std::string input;
	int sum = 0, length = 0;

	std::cin >> length;
	std::cin >> input;

	for (char getC : input) {
		if (isdigit(getC)) {
			stack.push(getC - '0');
		}
		else {
			sum += popStackNumbers(stack);
		}
	}
	sum += popStackNumbers(stack);

	std::cout << sum;
}

int popStackNumbers(std::stack<int>& stack) {
	int n = 1, sum = 0;
	while (!stack.empty()) {
		sum += stack.top() * n;
		stack.pop();
		n *= 10;
	}

	return sum;
}