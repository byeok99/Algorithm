#include <bits/stdc++.h>
using namespace std; 

int a, b, v, posi, cnt; 
int main() {
	cin >> a >> b >> v; 

	if (v < a) {
		cout << 1; 
	}
	else {
		if ((v - a) % (a - b) == 0) {
			cout << (v - a) / (a - b) + 1;
		}
		else {
			cout << (v - a) / (a - b) + 2;
		}
	}
}