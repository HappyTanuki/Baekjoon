#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define UINF _UINF
#define INF _INF

constexpr unsigned int _UINF = 4294967295;
constexpr int _INF = 2147483647;

struct DataType {
	int dest;
	int cost;
	int weight;
};

struct cmp {
	bool operator()(DataType a, DataType b) {
		return a.weight > b.weight;
	}
};

void dijkstra(int V0, vector<vector<DataType>> adj, vector<int>& distance, int N, int M) {
	priority_queue<DataType, vector<DataType>, cmp> pQueue;

	vector<vector<int>> visited(adj.size(), vector<int>{ 0, INF});
	DataType current;
	distance[V0] = 0;

	pQueue.push({ V0 - 1, 0, 0 });
	while (!pQueue.empty()) {
		current = pQueue.top();
		pQueue.pop();

		if (visited[current.dest][0] && visited[current.dest][1] < current.cost) {
			continue;
		}

		if (visited[N - 1][0]) {
			break;
		}

		distance[current.dest] = current.weight;

		visited[current.dest][0] = true;
		visited[current.dest][1] = current.cost;

		for (auto V : adj[current.dest]) {
			if (current.cost + V.cost <= M) {
				pQueue.push({ V.dest, current.cost + V.cost, distance[current.dest] + V.weight });
			}
		}
	}

	return;
}

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);

	int T = 0, N = 0, M = 0, K = 0;
	int u = 0, v = 0, c = 0, d = 0;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> N >> M >> K;

		vector<vector<DataType>> adj(N);
		vector<int> result(N, INF);

		for (int j = 0; j < K; j++) {
			cin >> u >> v >> c >> d;

			adj[u - 1].push_back({ v - 1, c, d });
		}

		dijkstra(1, adj, result, N, M);

		if (result[N - 1] == INF) {
			std::cout << "Poor KCM" << '\n';
		}
		else {
			std::cout << result[N - 1] << '\n';
		}
	}
}