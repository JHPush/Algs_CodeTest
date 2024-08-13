#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 100000;
int n, k;
int visited[MAX + 1], prevP[MAX + 1];
vector<int> path;

void BFS(int here) {
	queue<int> q;
	q.push(here);
	visited[here] = 1;

	while (q.size()) {
		int p = q.front();
		q.pop();
		if (p == k) {
			break;
		}
		for (int next : {p - 1, p + 1, p * 2}) {
			if (next <0 || next > MAX) continue;

			if (!visited[next]) {
				visited[next] = visited[p] + 1;
				q.push(next);
				prevP[next] = p;
			}
		}
	}
	for (int i = k; i != n; i = prevP[i]) {
		path.push_back(i);
	}
	path.push_back(n);
}

int main() {
	cin >> n >> k;
	BFS(n);
	reverse(path.begin(), path.end());

	cout << visited[k] - 1 << '\n';
	for (auto v : path) {
		cout << v << ' ';
	}
}