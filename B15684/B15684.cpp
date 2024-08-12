#include <iostream>

using namespace std;

int n, m, h, ret = INT32_MAX;
int visited[301][11];

bool Check() {
	for (int i = 1; i <= n; i++) {
		int start = i;
		for (int j = 1; j <= h; j++) {
			if (visited[j][start])start++;
			else if (visited[j][start - 1])start--;
		}
		if (start != i)return false;
	}
	return true;
}
void go(int here, int cnt) {
	if (cnt > 3 || cnt >= ret) return;
	if (Check()) {
		ret = min(ret, cnt);
		return;
	}
	for (int i = here; i <= h; i++) {
		for (int j = 1; j < n; j++) {
			if (visited[i][j] || visited[i][j - 1] || visited[i][j + 1]) continue;
			visited[i][j] = 1;
			go(i, cnt + 1);
			visited[i][j] = 0;
		}
	}
}

int main() {
	cin.tie(NULL);
	cin >> n >> m >> h;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		visited[a][b] = 1;
	}
	go(1, 0);
	cout << ((ret == INT32_MAX) ? -1 : ret);

}