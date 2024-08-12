#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int k;
vector<int> ret[14];
int li[1030];

void go(int s, int e, int depth) {
	if (s > e) return;
	if (s == e) {
		ret[depth].push_back(li[s]);
		return;
	}
	int mid = (s + e) / 2;;
	ret[depth].push_back(li[mid]);
	go(s, mid - 1, depth + 1);
	go(mid + 1, e, depth + 1);
}


int main() {
	cin >> k;
	int end = pow(2, k) - 1;
	for (int i = 0; i < end; i++) {
		cin >> li[i];
	}

	go(0, end, 1);
	for (int i = 1; i <= k; i++) {
		for (auto v : ret[i]) {
			cout << v << ' ';
		}
		cout << '\n';
	}

}