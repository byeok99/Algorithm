#include <bits/stdc++.h>
using namespace std; 

int main() {
	int n, h; 
	cin >> n; 
	stack<pair<int, int>> s; 

	for (int i = 0; i < n; i++) {
		cin.tie(0);
		ios_base::sync_with_stdio(false);
		cin >> h; 
		while (!s.empty()) {
			if (h < s.top().second) {
				cout << s.top().first << " ";
				break; 
			}
			s.pop(); 
		}
		if (s.empty()) {
			cout << 0 << " "; 
		}
		s.push({ i + 1, h }); 
	}
}