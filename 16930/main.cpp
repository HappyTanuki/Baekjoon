#include <iostream>
#include <queue>
#include <tuple>

enum {
	X,
	Y,
	COUNT
};

int bfs(char** map, int N, int M, int K, int x1, int y1, int x2, int y2) {
	int*** visited = new int** [N];
	for (int i = 0; i < N; i++) {
		visited[i] = new int*[M];
		for (int j = 0; j < M; j++) {
			visited[i][j] = new int[2];
		}
	}
	std::queue<std::tuple<int, int, int>> queue;
	std::tuple<int, int, int> current;
	int x = 0, y = 0;
	int count = 0;
	int direction[4][2] = { {-1, 0},
							{0, -1},
							{1,  0},
							{0,  1} };

	queue.push(std::make_tuple(x1 - 1, y1 - 1, 0));
	visited[0][0][0] = true;
	visited[0][0][1] = 0;
	while (!queue.empty()) {
		current = queue.front();
		queue.pop();

		x = std::get<X>(current);
		y = std::get<Y>(current);
		count = std::get<COUNT>(current);

		if (x == x2 - 1 && y == y2 - 1) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					delete[] visited[i][j];
				}
				delete[] visited[i];
			}
			delete[] visited;

			return count;
		}

		for (int i = 0; i < 4; i++) {
			for (int multiplier = 1; multiplier <= K; multiplier++) {
				int tx = x + direction[i][0] * multiplier;
				int ty = y + direction[i][1] * multiplier;
				if ((tx >= 0) && (ty >= 0) && (tx < N) && (ty < M)) {
					if ((visited[tx][ty][0] == 0) && map[tx][ty] == '.' && ((visited[tx][ty][1] > count + 1 ) || visited[tx][ty][0] == 0)) {
						queue.push(std::make_tuple(tx, ty, count + 1));
						visited[tx][ty][0] = 1;
						visited[tx][ty][1] = count + 1;
					}
					else if ((visited[tx][ty][1] < count + 1)) {
						break;
					}
					else if (map[tx][ty] == '.');
					else {
						break;
					}
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			delete[] visited[i][j];
		}
		delete[] visited[i];
	}
	delete[] visited;

	return -1;
}

int main() {
	std::ios::sync_with_stdio(NULL);
	std::cin.tie(NULL);

	std::string input;
	int N = 0, M = 0, K = 0;
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;

	std::cin >> N >> M >> K;


	char** map = new char* [N];
	for (int i = 0; i < N; i++) {
		map[i] = new char[M];
	}

	for (int i = 0; i < N; i++) {
		std::cin >> input;
		for (int j = 0; j < M; j++) {
			map[i][j] = input[j];
		}
	}

	std::cin >> x1 >> y1 >> x2 >> y2;

 	std::cout << bfs(map, N, M, K, x1, y1, x2, y2);


	for (int i = 0; i < N; i++) {
		delete[] map[i];
	}
	delete[] map;
}