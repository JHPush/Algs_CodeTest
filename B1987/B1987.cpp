#include <iostream>

using namespace std;

int n, m, ret;
const int MAX = 21;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1,0,-1 };

char lv[MAX][MAX];
int visited[26];

void DFS(pair<int,int> here, int cnt) {
	ret = max(ret, cnt);
	for (int i = 0; i < 4; i++) {
		int ny = dy[i] + here.first;
		int nx = dx[i] + here.second;

		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		int next = lv[ny][nx] - 'A';
		if (!visited[next] ) {
			visited[next] = 1;
			DFS({ ny, nx }, cnt + 1);
			visited[next] = 0;
		}
	}
}

int main() {
	cin.tie(NULL);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> lv[i][j];
		}
	}

	visited[lv[0][0] - 'A'] = 1;
	DFS({ 0,0 }, 1);
	cout << ret;

	return 0;
}