#include <bits/stdc++.h>
using namespace std; 

int n; 

bool check(string s) {
	int len = s.length(); 

	for (int i = 1; i <= len / 2; i++) {
		string s1 = s.substr(len - (i * 2), i);
		string s2 = s.substr(len - i, i); 
		if (s1 == s2) return true;
	}
	return false;
}

void dfs(int depth, string s) {
	if (check(s)) return; 
	if (depth == n) {
		cout << s << "\n"; 
		exit(0);
	}

	dfs(depth + 1, s + '1'); 
	dfs(depth + 1, s + '2');
	dfs(depth + 1, s + '3');
}

int main() {
	cin >> n; 
	dfs(0, "");
	return 0;
}