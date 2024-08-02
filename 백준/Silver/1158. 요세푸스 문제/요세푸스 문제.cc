#include <bits/stdc++.h>
using namespace std; 

int n, k, temp;
queue<int> q; 
int main() {
	cin >> n >> k; 

	for (int i = 1; i <= n; i++) {
		q.push(i); 
	}
	cout << "<";
	while (!q.empty()) {
		for (int i = 1; i <= k; i++) {
			temp = q.front(); 
			q.pop(); 
			if (i != k) {
				q.push(temp); 
			}
			else {
				cout << temp; 
			}
		}
		if (!q.empty()) cout << ", ";
	}
	cout << ">";
}