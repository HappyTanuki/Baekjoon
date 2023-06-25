#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

bool compare(int a, int b) {
	return b < a;
}

typedef struct queuedDataType {
	int data[13] = { 0, };
	std::vector<bool> permutation;
};

int main() {
	queuedDataType data;
	std::queue<queuedDataType> inputQueue;
	int K = 0, j = 0;
	int output[6] = { 0, };

	std::cin >> K;
	while (K != 0) {
		for (int i = 0; i < 13; i++) {
			data.data[i] = 0;
		}
		data.permutation.clear();
		for (int i = 0; i < K; i++) {
			std::cin >> data.data[i];
			if (i >= K - 6) {
				data.permutation.push_back(true);
			}
			else {
				data.permutation.push_back(false);
			}
		}
		std::sort(data.data, data.data + 13, compare);
		inputQueue.push(data);
		std::cin >> K;
	}

	while (!inputQueue.empty()) {
		data = inputQueue.front();
		inputQueue.pop();

		do {
			j = 0;
			for (int i = 0; i < data.permutation.size(); i++) {
				if (data.permutation[i]) {
					output[j++] = data.data[i];
				}
			}
			std::sort(output, output + 6);

			for (int i = 0; i < 6; i++) {
				std::cout << output[i] << ' ';
			}
			std::cout << '\n';

		} while (std::next_permutation(data.permutation.begin(), data.permutation.end()));

		std::cout << '\n';
	}
}