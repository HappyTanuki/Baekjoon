#include <iostream>
#include <vector>
#include <queue>

#define UINF _UINF
#define INF _INF

constexpr unsigned int _UINF = 4294967295;
constexpr int _INF = 2147483647;

struct Cmp {
	bool operator()(std::pair<unsigned int, unsigned int> a, std::pair<unsigned int, unsigned int> b) {
		if (a.second > b.second) {
			return true;
		}
		else {
			return false;
		}
	}
};

void dijkstra(const int V0, std::vector<std::vector<std::pair<unsigned int, unsigned int>>> adj, std::vector<unsigned int> &distance) {
	std::priority_queue<std::pair<unsigned int, unsigned int>, std::vector<std::pair<unsigned int, unsigned int>>, Cmp> pQueue;

	std::vector<bool> visited(adj.size(), false);
	std::pair<unsigned int, unsigned int> current;
	distance[V0] = 0;

	pQueue.push(std::make_pair(V0 - 1, 0));
	while (!pQueue.empty()) {
		current = pQueue.top();
		pQueue.pop();

		if (visited[current.first]) {
			continue;
		}

		distance[current.first] = current.second;

		visited[current.first] = true;

		for (auto V : adj[current.first]) {
			pQueue.push(std::make_pair(V.first, distance[current.first] + V.second));
		}
	}

	return;
}

int main() {
	std::ios::sync_with_stdio(NULL);
	std::cin.tie(NULL);

	int V = 0, E = 0, u = 1, v = 1, w = 0;
	int V0 = 0;

	std::cin >> V >> E >> V0;

	std::vector<std::vector<std::pair<unsigned int, unsigned int>>> adj(V);
	std::vector<unsigned int> result(V, UINF);

	for (int i = 0; i < E; i++) {
		std::cin >> u >> v >> w;
		adj[u - 1].push_back(std::make_pair(v - 1, w));
	}

	dijkstra(V0, adj, result);
	for (auto i : result) {
		if (i == UINF) {
			std::cout << "INF" << '\n';
		}
		else {
			std::cout << i << '\n';
		}
	}
}