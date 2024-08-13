#include <iostream>
#include <queue>

using namespace std;

int n, k, turn = 1;
const int MAX = 500000;
int visited[2][MAX + 1];
bool ok;

void BFS(int here) {
	queue<int> q;
	visited[0][here] = 1;
	q.push(here);

	while (q.size()) {
		k += turn;
		if (k > MAX) break;
		if (visited[turn % 2][k]) {
			ok = true;
			break;
		}
		int qSize = q.size();
		for (int i = 0; i < qSize; i++) {
			int p = q.front();
			q.pop();

			for (int np : {p - 1, p + 1, p * 2}) {
				if (np <0 || np > MAX || visited[turn % 2][np])
					continue;
				visited[turn % 2][np] = visited[(turn + 1) % 2][p] + 1;
				if (np == k) {
					ok = true;
					break;
				}
				q.push(np);
			}
			if (ok) break;
		}
		if (ok) break;
		turn++;
	}

}

int main() {
	cin >> n >> k;
	if (n == k) {
		cout << 0;
		return 0;
	}
	BFS(n);
	if (ok)
		cout << turn;
	else
		cout << -1;
}