#include <iostream>
#include <queue>
#include <tuple>

enum {
	X,
	Y,
	COUNT,
	HAMMER
};

int bfs(int **map, int N, int M) {
	bool*** visited = new bool** [N];
	for (int i = 0; i < N; i++) {
		visited[i] = new bool* [M];
		for (int j = 0; j < M; j++) {
			visited[i][j] = new bool[2] { false, };
		}
	}
	std::queue<std::tuple<int, int, int, bool>> queue;
	std::tuple<int, int, int, bool> current;
	int x = 0, y = 0;
	int count = 0;
	bool hammer = true;
	int direction[4][2] = { {-1, 0},
							{0, -1},
							{1,  0},
							{0,  1} };

	queue.push(std::make_tuple( 0, 0, 1, true ));
	visited[0][0][true] = true;
	while (!queue.empty()) {
		current = queue.front();
		queue.pop();

		x = std::get<X>(current);
		y = std::get<Y>(current);
		count = std::get<COUNT>(current);
		hammer = std::get<HAMMER>(current);

		if (x == N - 1 && y == M - 1) {

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
			int tx = x + direction[i][0];
			int ty = y + direction[i][1];
			if ((tx >= 0) && (ty >= 0) && (tx < N) && (ty < M)) {
				if ((map[tx][ty] == 1 && hammer) || map[tx][ty] == 0) {
					if (!visited[tx][ty][hammer]) {
						if (map[tx][ty] == 1 && hammer) {
							hammer = false;
							queue.push(std::make_tuple(tx, ty, count + 1, hammer));
							visited[tx][ty][hammer] = true;
							hammer = true;
						}
						else {
							queue.push(std::make_tuple(tx, ty, count + 1, hammer));
							visited[tx][ty][hammer] = true;
						}
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
	std::string input;
	int N = 0, M = 0;

	std::cin >> N >> M;


	int** map = new int* [N];
	for (int i = 0; i < N; i++) {
		map[i] = new int[M];
	}

	for (int i = 0; i < N; i++) {
		std::cin >> input;
		for (int j = 0; j < M; j++) {
			map[i][j] = input[j] - '0';
		}
	}

	std::cout << bfs(map, N, M);

	
	for (int i = 0; i < N; i++) {
		delete[] map[i];
	}
	delete[] map;
}