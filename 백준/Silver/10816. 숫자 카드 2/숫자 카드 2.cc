#include <bits/stdc++.h>
using namespace std; 

int n, m, temp; 
map<int,int> n_map; 
vector<int> m_map;
int main() {
	cin.tie(0);
	cout.tie(0); 
	ios::sync_with_stdio(false);

	cin >> n; 
	for (int i = 0; i < n; i++) {
		cin >> temp; 
		n_map[temp] = n_map[temp]+1; 
	}
	
	cin >> m; 
	for (int i = 0; i < m; i++) {
		cin >> temp;
		m_map.push_back(temp);
	}

	for (int i : m_map) {
		if (n_map[i]) cout << n_map[i] << " ";
		else cout << 0 << " ";
	}
}