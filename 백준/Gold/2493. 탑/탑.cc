#include <bits/stdc++.h> 
using namespace std; 

int n, temp;
stack<pair<int,int>> stk;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n; 
	for (int i = 0; i < n; i++) {
		cin >> temp; 

		while (!stk.empty() && stk.top().first < temp) stk.pop(); 

		if (stk.empty()) cout << "0 ";
		else cout << stk.top().second+1 << " ";

		stk.push({ temp, i });
	}
}