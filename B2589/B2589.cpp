// BFS

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int h, w, ret;
char land[50][50];
int visited[50][50];
vector<pair<int, int>> ground;

int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

void BFS(pair<int, int> pos) {
	visited[pos.first][pos.second] = 1;
	queue<pair<int, int>> q;
	q.push(pos);

	while (q.size()) {
		pair<int, int> p = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = dy[i] + p.first;
			int nx = dx[i] + p.second;

			if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
			if (land[ny][nx] == 'W' || visited[ny][nx]) continue;
			q.push({ ny,nx });
			visited[ny][nx] = visited[p.first][p.second] + 1;
			ret = max(visited[ny][nx], ret);
		}
	}
}

int main() {
	cin.tie(NULL);
	cin >> h >> w;

	for (int i = 0; i < h; i++) {
		string s = "";
		cin >> s;
		int j = 0;
		for (auto ss : s) {
			if (ss == 'L')
				ground.push_back({ i, j });
			land[i][j] = ss;
			j++;
		}
	}
	for (auto g : ground) {
		int cnt = 0;
		fill(&visited[0][0], &visited[0][0] + 50 * 50, 0);

		for (int i = 0; i < 4; i++) {
			int ny = dy[i] + g.first;
			int nx = dx[i] + g.second;
			if (land[ny][nx] == 'W' || ny < 0 || ny >= h || nx < 0 || nx >= w)
				cnt++;
		}
		if (cnt >= 2)
			BFS(g);
	}
	cout << max(0, ret - 1);
}