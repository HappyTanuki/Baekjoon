#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <queue>

typedef struct _Instruction {
	char data[5] = { 0, };
}InstructionType;

int main() {
	char input[600000];
	char* inputTop = nullptr;
	std::queue<InstructionType> instructionQueue;
	InstructionType instruction;

	std::stack<char> stack;
	int intructionCount = 0;

	scanf("%s", input);
	inputTop = input + (strlen(input) - 1);

	scanf("%d ", &intructionCount);

	for (int i = 0; i < intructionCount; i++) {
		fgets(instruction.data, 5, stdin);
		instruction.data[3] = 0;
		instructionQueue.push(instruction);
	}

	while (!instructionQueue.empty()) {
		instruction = instructionQueue.front();
		instructionQueue.pop();

		switch (instruction.data[0]) {
		case 'L':
			if (inputTop >= input) {
				stack.push(*inputTop--);
			}
			break;
		case 'D':
			if (!stack.empty()) {
				*(++inputTop) = stack.top();
				stack.pop();
			}
			break;
		case 'B':
			if (inputTop >= input) {
				inputTop--;
			}
			break;
		case 'P':
			*(++inputTop) = instruction.data[2];
			break;
		}
	}
	*(++inputTop) = 0;

	printf("%s", input);

	while (!stack.empty()) {
		printf("%c", stack.top());
		stack.pop();
	}
}