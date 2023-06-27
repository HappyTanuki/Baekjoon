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
	int K = 0, j = 0, cnt = 0;

	std::vector<std::vector<std::vector<int>>> output;
	std::vector<std::vector<int>> temp;
	std::vector<int> temp2;

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
		inputQueue.push(data);
		std::cin >> K;
	}

	cnt = 0;
	while (!inputQueue.empty()) {
		output.push_back(temp);
		data = inputQueue.front();
		inputQueue.pop();

		j = 0;
		do {
			output[cnt].push_back(temp2);
			for (int i = 0; i < data.permutation.size(); i++) {
				if (data.permutation[i]) {
					output[cnt][j].push_back(data.data[i]);
				}
			}
			j++;
		} while (std::next_permutation(data.permutation.begin(), data.permutation.end()));

		cnt++;
	}

	for (int i = 0; i < output.size(); i++) {
		std::sort(output[i].begin(), output[i].end());
	}

	for (int i = 0; i < output.size(); i++) {
		for (int j = 0; j < output[i].size(); j++) {
			for (int k = 0; k < output[i][j].size(); k++) {
				std::cout << output[i][j][k] << ' ';
			}
			std::cout << '\n';
		}
		std::cout << '\n';
	}
}