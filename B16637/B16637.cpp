#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, ret = INT32_MIN;
string s;
vector<int> nums;
vector<char> opers;

int oper(char op, int a, int b) {
	if (op == '+') return a + b;
	if (op == '-') return a - b;
	if (op == '*') return a * b;
}

void solve(int idx, int _num) {
	if (idx == nums.size() - 1) {
		ret = max(ret, _num);
		return;
	}
	solve(idx + 1, oper(opers[idx], _num, nums[idx + 1]));

	if (idx + 2 <= nums.size() - 1) {
		int temp = oper(opers[idx + 1], nums[idx + 1], nums[idx + 2]);
		solve(idx + 2, oper(opers[idx], _num, temp));
	}
}


int main() {
	cin.tie(NULL);
	cin >> n;
	cin >> s;

	for (int i = 0; i < n; i++) {
		if (i % 2 == 0)
			nums.push_back(s[i] - '0');
		else
			opers.push_back(s[i]);
	}
	solve(0, nums[0]);
	cout << ret;
}