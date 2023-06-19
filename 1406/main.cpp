#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char* input = (char*)calloc(600000, sizeof(char));
	char* inputTop = (input - 1);

	char* stack = (char*)calloc(600000, sizeof(char));
	char* stackTop = (stack - 1);

	char instruction[5];
	int intructionCount = 0;

	fscanf(stdin, "%s", input);
	inputTop = input + (strlen(input) - 1);

	scanf("%d\n", &intructionCount);

	for (int i = 0; i < intructionCount; i++) {
		fgets(instruction, 5, stdin);

		switch (instruction[0]) {
		case 'L':
			if (inputTop >= input) {
				*(++stackTop) = *(inputTop--);
			}
			break;
		case 'D':
			if (stackTop >= stack) {
				*(++inputTop) = *(stackTop--);
			}
			break;
		case 'B':
			if (inputTop >= input) {
				inputTop--;
			}
			break;
		default:
			*(++inputTop) = instruction[2];
			break;
		}
	}
	while (stackTop >= stack) {
		*(++inputTop) = *(stackTop--);
	}
	*(++inputTop) = 0;

	fwrite(input, sizeof(char), inputTop - input, stdout);
}