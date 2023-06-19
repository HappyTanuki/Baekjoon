#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char* input = (char*)calloc(600000, sizeof(char));
	char* inputTop = (input - 1);

	char* stack = (char*)calloc(600000, sizeof(char));
	char* stackTop = (stack - 1);

	char instruction;
	int intructionCount = 0;

	fscanf(stdin, "%s", input);
	inputTop = input + (strlen(input) - 1);

	scanf("%d", &intructionCount);

	getchar(); // \n 무시
	for (int i = 0; i < intructionCount; i++) {
		instruction = getchar();

		switch (instruction) {
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
			getchar();
			*(++inputTop) = getchar();
			break;
		}
		getchar(); //\n무시
	}
	*(++inputTop) = 0;

	fwrite(input, sizeof(char), inputTop - input, stdout);

	while (stackTop >= stack) {
		putchar(*stackTop--);
	}
}