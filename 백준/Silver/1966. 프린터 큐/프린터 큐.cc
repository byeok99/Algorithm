#include <bits/stdc++.h>
using namespace std; 

int n, m, t, temp;
bool cmp(int a, int b) {
	return a > b; 
}
int main() {
	cin >> t; 
	while (t--) {
		queue<pair<int,int>> q;
		vector<int> v;
		int ret=0; 
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> temp; 
			v.push_back(temp);
			if (i == m) q.push({ temp, 1 });
			else q.push({ temp, 0 });
		}

		sort(v.begin(), v.end(), cmp); 

		while (!q.empty()) {
			int f, s;
			tie(f,s) = q.front();
			q.pop();

			if (v[0] == f) {
				ret++;
				if (s == 1) {
					cout << ret << "\n";
					break;
				}
				v.erase(v.begin()); 
			}
			else {
				q.push({ f,s }); 
			}
		}
	}
}