#include <iostream>
#include <cstring>
#include <stack>

int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	std::string input;
	int inputSize = 0;
	std::string bomb;
	int bombSize = 0;

	std::string output;
	std::stack<char> stack;

	std::cin >> input;
	inputSize = input.length();
	std::cin >> bomb;
	bombSize = bomb.length();

	for (int i = 0; i < inputSize; i++) {
		output.push_back(input[i]);

		for (int j = bombSize - 1; j >= 0; j--) {
			if (!output.empty()) {
				if (output.back() == bomb[j]) {
					stack.push(output.back());
					output.pop_back();
				}
				else {
					while (!stack.empty()) {
						output.push_back(stack.top());
						stack.pop();
					}
					break;
				}
			}
			else {
				while (!stack.empty()) {
					output.push_back(stack.top());
					stack.pop();
				}
			}
		}
		while (!stack.empty()) {
			stack.pop();
		}
	}

	if (!output.empty()) {
		std::cout << output;
	}
	else {
		std::cout << "FRULA";
	}
}