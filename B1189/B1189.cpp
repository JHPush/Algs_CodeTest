#include <iostream>

using namespace std;

int n, m, k;
char lv[6][6];
int visited[6][6];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };


int DFS(int y, int x) {
	if (y == 0 && x == m - 1) {
		if (visited[y][x] == k) return 1;
		return 0;
	}
	int ret = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= n || nx < 0 || nx >= m || lv[ny][nx] == 'T' || visited[ny][nx]) continue;
		visited[ny][nx] = visited[y][x] + 1;
		ret += DFS(ny, nx);
		visited[ny][nx] = 0;
	}
	return ret;
}

int main() {
	cin.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> lv[i][j];
		}
	}
	visited[n - 1][0] = 1;
	cout << DFS(n - 1, 0);
}