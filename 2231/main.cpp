#include <iostream>
#include <string>

int getDecompositSum(int number) {
	int numberSum = number;

	while (number != 0) {
		numberSum += number % 10;
		number /= 10;
	}

	return numberSum;
}

int main() {
	char input[10] = { 0, };
	char output[10] = { 0, };
	int decompositSum = 0;
	int testInt = 0;

	//fgets(input, sizeof(input), stdin);
	//decompositSum = std::stoi(input);

	std::cin >> decompositSum;

	for (testInt = 1; testInt < decompositSum; testInt++) {
		if (getDecompositSum(testInt) == decompositSum) {
			break;
		}
	}

	if (testInt == decompositSum) {
		testInt = 0;
	}

	std::cout << testInt;

	//sprintf_s(output, sizeof(output), "%d", testInt);
	//fwrite(output, sizeof(char), sizeof(output), stdout);
}