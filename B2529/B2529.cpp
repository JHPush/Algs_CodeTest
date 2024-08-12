#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int k, visited[10];
char oper[11];
vector<string> ret;

bool checkNum(char before, char after, char oper) {
	if (before < after && oper == '<') return true;
	if (before > after && oper == '>') return true;
	return false;
}

void go(int idx, string num) {
	if (idx == k + 1) {
		ret.push_back(num);
		return;
	}
	for (int i = 0; i <= 9; i++) {
		if (visited[i]) continue;
		if (idx == 0 || checkNum(num[idx - 1], i + '0', oper[idx - 1])) {
			visited[i] = 1;
			go(idx + 1, num + to_string(i));
			visited[i] = 0;
		}
	}
}

int main() {
	cin >> k;
	
	for (int i = 0; i < k; i++) 
		cin >> oper[i];
	go(0, "");
	sort(ret.begin(), ret.end());
	cout << ret.back() << '\n' << ret.front();

	
}