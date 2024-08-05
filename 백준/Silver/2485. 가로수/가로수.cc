#include <bits/stdc++.h>
using namespace std; 

int n, input, _gcd, _count;
vector<int> v, v2; 

int euclidean(int a, int b) {
	if (b == 0) return a;
	return euclidean(b, a % b);
}

int main() {
	cin >> n; 
	for (int i = 0; i < n; i++) {
		cin >> input; 
		v.push_back(input);
	}

	for (int i = 1; i < v.size(); i++) {
		v2.push_back(v[i] - v[i - 1]);
	}

	_gcd = v2[0];
	for (int i = 1; i < v2.size(); i++) {
		_gcd = euclidean(v2[i], _gcd);
	}

	for (int i = 0; i < v2.size(); i++) {
		_count += (v2[i] / _gcd) - 1;
	}

	
	cout << _count;
}