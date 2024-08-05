#include <bits/stdc++.h>
using namespace std; 

int n, m, ret = 987654321, temp;
vector<pair<int, int>> ch, home; 
vector<vector<int>> combiList ; 

void combi(int depth, vector<int> v) {
	if (v.size() == m) {
		combiList.emplace_back(v);
		return; 
	}

	for (int i = depth + 1; i < ch.size(); i++) {
		v.push_back(i); 
		combi(i, v); 
		v.pop_back();
	}
}

int main() {
	cin >> n >> m; 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> temp; 
			if (temp == 1) home.push_back({ i,j });
			else if (temp == 2) ch.push_back({ i,j }); 
		}
	}

	combi(-1, vector<int>()); 

	for (vector<int> cbList : combiList) {
		int sum = 0;
		for (pair<int, int> h : home) {
			int _min = 987654321; 
			for (int i : cbList) {
				int _dist = abs(h.first - ch[i].first) + abs(h.second - ch[i].second);
				_min = min(_min, _dist); 
			}
			sum += _min; 
		}
		ret = min(ret, sum); 
	}
	cout << ret; 
}