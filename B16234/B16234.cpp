#include <iostream>
#include <queue>
#include <vector>
#include <numeric>
using namespace std;

int world[50][50];
int visited[50][50];
vector<vector<pair<int, int>>> uni;
vector<int> uni_p;

int n, l, r, ret;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

void BFS(pair<int, int> here) {
	vector<pair<int, int>> u;
	int num = world[here.first][here.second];
	queue<pair<int, int>> q;
	q.push(here);
	u.push_back(here);
	visited[here.first][here.second] = 1;

	while (q.size()) {
		pair<int, int> pos = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = pos.first + dy[i];
			int nx = pos.second + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
			if (visited[ny][nx] || !(abs(world[ny][nx] - world[pos.first][pos.second]) >= l && abs(world[ny][nx] - world[pos.first][pos.second]) <= r))
				continue;
			q.push({ ny, nx });
			visited[ny][nx] = 1;
			u.push_back({ ny,nx });
			num += world[ny][nx];
		}
	}
	if (u.size() != 1) {
		uni.push_back(u);
		uni_p.push_back(num / u.size());
	}
}

void Solve() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j])
				BFS({ i,j });
		}
	}
	if (uni.empty())
		cout << ret;
	else {
		ret++;
		fill(&visited[0][0], &visited[0][0] + 50 * 50, 0);
		for (int i = 0; i < uni.size(); i++) {
			for (auto un : uni[i]) {
				world[un.first][un.second] = uni_p[i];
			}
		}
		uni.clear();
		uni_p.clear();
		Solve();
	}

}

int main() {
	cin.tie(NULL);
	cin >> n >> l >> r;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> world[i][j];
		}
	}
	Solve();
}