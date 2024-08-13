#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, ret = INT32_MAX;
char maze[1000][1000];
int JVisited[1000][1000];
int FVisited[1000][1000];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1,0,-1 };
pair<int, int> jj;
vector<pair<int, int>> f;
vector<int> goalCnt;

void BFS(pair<int, int> here) {
	queue<pair<int, int>> q;

	if (here != jj) {
		q.push(here);
		FVisited[here.first][here.second] = 1;

		while (q.size()) {
			pair<int, int> pos = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int ny = pos.first + dy[i];
				int nx = pos.second + dx[i];

				if (ny < 0 || ny >= n || nx < 0 || nx >= m || maze[ny][nx] == '#') continue;
				if (FVisited[ny][nx] != 0 && FVisited[ny][nx] <= FVisited[pos.first][pos.second] + 1)
					continue;

				FVisited[ny][nx] = FVisited[pos.first][pos.second] + 1;
				q.push({ ny,nx });
			}
		}
	}
	else {

		q.push(jj);
		JVisited[jj.first][jj.second] = 1;
		while (q.size()) {
			pair<int, int> pos = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int ny = pos.first + dy[i];
				int nx = pos.second + dx[i];

				if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
					goalCnt.push_back(JVisited[pos.first][pos.second]);
					continue;
				}
				if (maze[ny][nx] == '#' || JVisited[ny][nx] || maze[ny][nx] == 'F' || (FVisited[ny][nx] != 0 && FVisited[ny][nx] <= JVisited[pos.first][pos.second] + 1))
					continue;

				q.push({ ny,nx });
				JVisited[ny][nx] = JVisited[pos.first][pos.second] + 1;
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> maze[i][j];
			if (maze[i][j] == '.' || maze[i][j] == '#')
				continue;
			else if (maze[i][j] == 'J')
				jj = { i,j };
			else
				f.push_back({ i,j });
		}
	}

	for (auto ff : f)
		BFS(ff);
	BFS(jj);
	sort(goalCnt.begin(), goalCnt.end());

	goalCnt.empty() ? cout << "IMPOSSIBLE" : cout << goalCnt.front();
}