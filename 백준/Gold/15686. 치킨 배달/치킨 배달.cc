#include <bits/stdc++.h> 
using namespace std; 

int n, m, result=999999999;
vector<pair<int, int>> one, two; 
vector<vector<int>> combiList; 

void combi(int depth, vector<int> v) {
	if (v.size() == m) {
		combiList.push_back(v);
		return; 
	}

	for (int i = depth+1; i < two.size(); i++) {
		v.push_back(i); 
		combi(i, v); 
		v.pop_back(); 
	}
	return; 
}
int main() {
	cin >> n >> m; 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int a; 
			cin >> a; 
			if (a == 1) one.push_back({ i,j });
			else if (a == 2) two.push_back({ i,j }); 
		}
	}
	vector<int> v;
	combi(-1, v);
	
	for (auto cList : combiList) {
		int ret = 0; 
		for (auto home : one) {
			int _min = 999999999;
			for (auto ch : cList) {
				int _dist = abs(home.first - two[ch].first) + abs(home.second - two[ch].second);
				_min = min(_min, _dist); 
			}
			ret += _min; 
		}
		result = min(ret, result); 
	}
	cout << result; 

}