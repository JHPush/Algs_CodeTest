#include <iostream>

using namespace std;

int n, ret = INT32_MAX;
int lv[14][14], visited[14][14];
int dy[] = {-1, 0, 1, 0};
int dx[] = { 0, 1, 0, -1 };

bool Check(int y, int x) {
	if (visited[y][x]) return false;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx])
			return false;
	}
	return true;
}

int SetFlower(int y, int x) {
	visited[y][x] = 1;
	int hap = lv[y][x];
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		visited[ny][nx] = 1;
		hap += lv[ny][nx];
	}
	return hap;
}

void EraseFlower(int y, int x) {
	visited[y][x] = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		visited[ny][nx] = 0;
	}
}

void Go(int cnt, int hap) {
	if (cnt == 3) {
		ret = min(ret, hap);
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (Check(i, j)) {
				Go(cnt + 1, hap + SetFlower(i, j));
				EraseFlower(i, j);
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> lv[i][j];
		}
	}
	Go(0, 0);
	cout << ret;
}