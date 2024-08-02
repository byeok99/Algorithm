#include <bits/stdc++.h> 
using namespace std;

int k, s[14], ret[6];

void solve(int depth, int start) {
	if (depth == 6) {
		for (int i : ret) cout << i << " ";
		cout << "\n";
		return;
	}

	for (int i = start; i < k; i++) {
		ret[depth] = s[i];
		solve(depth + 1, i+1);
	}
}

int main() {
	while (cin >> k && k) {
		for (int i = 0; i < k; i++) {
			cin >> s[i];
		}

		solve(0, 0);
		cout << "\n";
	}
}