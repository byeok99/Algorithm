#include<bits/stdc++.h>
using namespace std; 

int n, temp, ret; 
vector<int> v; 

int main() {
	cin >> n; 
	for (int i = 0; i < n; i++) {
		cin >> temp; 
		v.push_back(temp); 
	}

	for (int i : v) {
		int flag = 0; 
		if (i <= 1) continue; 
		for (int j = 2; j*j <= i; j++) {
			if (i % j == 0) flag++;
		}
		if (flag == 0) ret++;
	}

	cout << ret; 
}