#include <iostream>
#include <cstring>
#include <stack>

int main() {
	std::string input;
	int inputSize = 0;
	std::string bomb;
	int bombSize = 0;

	std::stack<char> stack;
	std::stack<char> tempStack;

	std::cin >> input;
	inputSize = input.length();
	std::cin >> bomb;
	bombSize = bomb.length();

	for (int i = 0; i < inputSize; i++) {
		stack.push(input[i]);

		for (int j = bombSize - 1; j >= 0; j--) {
			if (!stack.empty()) {
				if (stack.top() == bomb[j]) {
					tempStack.push(stack.top());
					stack.pop();
				}
				else {
					while (!tempStack.empty()) {
						stack.push(tempStack.top());
						tempStack.pop();
					}
					break;
				}
			}
			else {
				while (!tempStack.empty()) {
					stack.push(tempStack.top());
					tempStack.pop();
				}
			}
		}
		while (!tempStack.empty()) {
			tempStack.pop();
		}
	}

	if (!stack.empty()) {
		while (!stack.empty()) {
			tempStack.push(stack.top());
			stack.pop();
		}
		while (!tempStack.empty()) {
			putchar(tempStack.top());
			tempStack.pop();
		}
	}
	else {
		std::cout << "FRULA";
	}
}