#include <bits/stdc++.h>
using namespace std; 

int n, m, temp; 
map<int,int> n_map; 
vector<int> m_map;
int main() {
	cin >> n; 
	for (int i = 0; i < n; i++) {
		cin >> temp; 
		n_map[temp] = 1; 
	}
	
	cin >> m; 
	for (int i = 0; i < m; i++) {
		cin >> temp;
		m_map.push_back(temp);
	}

	for (int i : m_map) {
		if (n_map[i] == 1) cout << 1 << " ";
		else cout << 0 << " ";
	}
}