#include <iostream>
#include <queue>

enum instructionType {
	NONE,
	COPY,
	PASTE,
	DELETE
};

struct queueType {
	int imojiCount;
	instructionType instruction;
	int clipboard;
	int depth;
};

int calcLeastTime(const int s) {
	int CImojiCount = 1;
	int clipboard = 0;
	int depth = 0;
	bool visited[1001][1001] = { false, };
	static std::queue<queueType> queue;
	queueType curInstruction;

	queue.push({ 1, NONE, 0, 0 });
	while (!queue.empty()) {
		curInstruction = queue.front();
		queue.pop();

		depth = curInstruction.depth;
		clipboard = curInstruction.clipboard;
		CImojiCount = curInstruction.imojiCount;

		switch (curInstruction.instruction) {
		case NONE:
			break;
		case COPY:
			clipboard = CImojiCount;
			break;
		case PASTE:
			CImojiCount += clipboard;
			break;
		case DELETE:
			CImojiCount--;
			break;
		}

		if (CImojiCount > 1000 || clipboard > 1000) {
			continue;
		}
		else if (visited[CImojiCount][clipboard]) {
			continue;
		}
		else {
			visited[CImojiCount][clipboard] = true;
		}

		if (CImojiCount == s) {
			return depth;
		}
		if (curInstruction.instruction != COPY) {
			queue.push({ CImojiCount, COPY, clipboard, depth + 1 });
		}
		if (clipboard > 0) {
			queue.push({ CImojiCount, PASTE, clipboard, depth + 1 });
		}
		if (CImojiCount > 1) {
			queue.push({ CImojiCount, DELETE, clipboard, depth + 1 });
		}
	}
}

int main() {
	int s = 0;

	std::cin >> s;

	std::cout << calcLeastTime(s);
}