#include <bits/stdc++.h>
using namespace std; 
int ret[6], num, lotto[14]; 

void dfs(int depth, int start) {
	if (depth == 6) {
		for (int i = 0; i < 6; i++) cout << ret[i] << " ";
		cout << "\n";
		return; 
	}

	for (int i = start; i < num; i++) {
		ret[depth] = lotto[i]; 
		dfs(depth + 1, i + 1);
	}
};

int main() {
	while (cin >> num && num) {
		for (int i = 0; i < num; i++) cin >> lotto[i]; 
		dfs(0, 0);
		cout << "\n";
	}
}