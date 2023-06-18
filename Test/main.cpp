#include <iostream>
#include <string>
#include <stack>

int popStackNumbers(std::stack<int>& stack) {
	int n = 1, sum = 0;
	while (!stack.empty()) {
		sum += stack.top() * n;
		stack.pop();
		n *= 10;
	}

	return sum;
}

int findNumber(std::string input) {
	std::stack<int> stack;
	int sum = 0;

	for (char getC : input) {
		if (isdigit(getC)) {
			stack.push(getC - '0');
		}
		else {
			sum += popStackNumbers(stack);
		}
	}
	sum += popStackNumbers(stack);

	return sum;
}

int main() {
	srand(time(NULL));
	std::string output;

	int length = 30;

	int count = 0;

	int sum = 0;
	int number = 0;
	int origin = 0;
	int ret = 0;
	while (++count) {
		output = { 0, };
		number = 0;
		sum = 0;
		for (int i = 0; i < length;) {
			/*
			for (int j = 0; (j < rand() % 6) && (i < length); j++) {
				output += rand() % 10 + '0';
				i++;
			}
			*/
			number = rand() % 1000000;
			output += std::to_string(number);
			sum += number;
			i += std::to_string(number).length();
			for (int j = 0; (j < rand() % 5 + 1) && (i < length); j++) {
				output += rand() % 26 + 'a';
				i++;
			}
		}
		ret = findNumber(output);

		std::cout << "Test case : " << count << std::endl;
		std::cout << output << "\t" << ret << ' ' << (bool)(ret == sum) << std::endl;

		if (ret != sum) {
			break;
		}
	}
}



