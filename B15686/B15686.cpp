// 조합
// 브루투포스

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<pair<int, int>> house;
vector<pair<int, int>> chik;
vector<vector<int>> chikList;
vector<int> cityDist;
int city[50][50];

void ChikCombi(int start, int pick, vector<int> b) {
	if (b.size() == pick) {
		chikList.push_back(b);
		return;
	}
	for (int i = start + 1; i < chik.size(); i++) {
		b.push_back(i);
		ChikCombi(i, pick, b);
		b.pop_back();
	}
	return;
}

int main() {
	cin.tie(NULL);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> city[i][j];
			if (city[i][j] == 1)
				house.push_back({ i,j });
			else if (city[i][j] == 2)
				chik.push_back({ i,j });
		}
	}
	for (int i = 1; i <= m; i++)
		ChikCombi(-1, i, vector<int>());

	for (auto c : chikList) {
		int city = 0;
		for (auto h : house) {
			int chikD = INT32_MAX;
			for (int i = 0; i < c.size(); i++) {
				chikD = min(chikD, abs(h.first - chik[c[i]].first) + abs(h.second - chik[c[i]].second));
			}
			city += chikD;
		}
		cityDist.push_back(city);
	}
	sort(cityDist.begin(), cityDist.end());
	cout << cityDist.front();
}