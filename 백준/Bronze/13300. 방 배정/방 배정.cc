#include <bits/stdc++.h> 
using namespace std; 

int man[7], wom[7], n, k, gender, grade, ret; 

int main() {
	cin >> n >> k; 

	for (int i = 0; i < n; i++) {
		cin >> gender >> grade; 

		if (gender) {
			man[grade]++; 
		}
		else {
			wom[grade]++; 
		}
	}

	for (int i = 1; i < 7; i++) {
		if (man[i] != 0) ret += man[i] / k; 
		if (wom[i] != 0) ret += wom[i] / k;
		if (man[i] % k != 0) ret++;
		if (wom[i] % k != 0) ret++; 
	}

	cout << ret << "\n";
}