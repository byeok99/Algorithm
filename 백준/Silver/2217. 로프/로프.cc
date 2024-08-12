#include <bits/stdc++.h>
using namespace std; 

int n, temp, _max, ret;
vector<int> v; 

int main() {
	cin >> n; 
	for (int i = 0; i < n; i++) {
		cin >> temp; 
		v.push_back(temp); 
	}

	sort(v.begin(), v.end()); 
	_max = v[n - 1]; 
	for (int i = n-1; i >= 0; i--) {
		ret = v[i] * (n - i); 
		_max = max(ret, _max); 
	}

	cout << _max; 
}