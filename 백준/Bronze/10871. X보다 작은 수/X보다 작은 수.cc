#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, x, _arr[10000];

	cin >> n >> x; 
	for (int i = 0; i < n; i++) {
		cin >> _arr[i]; 
	}

	for (int i = 0; i < n; i++) {
		if (_arr[i] < x) cout << _arr[i] << " ";
	}
}