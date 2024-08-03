#include<bits/stdc++.h>
using namespace std; 

int n, m; 
bool is_prime(int num) {
	bool flag = false; 
	for (int i = 2; i*i <= num; i++) {
		if (num % i == 0) flag = true; 
	}
	return flag; 
}

int main() {
	cin >> n >> m; 

	for (int i = n; i <= m; i++) {
		if (i > 1 && !is_prime(i)) cout << i << "\n";
	}
}