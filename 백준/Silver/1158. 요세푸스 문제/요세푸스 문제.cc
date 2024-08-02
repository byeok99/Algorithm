#include <bits/stdc++.h>
using namespace std; 

int n, k;
queue<int> q; 

int main() {
	cin >> n >> k; 

	for (int i = 1; i <= n; i++) {
		q.push(i); 
	}
	cout << "<";
	while (!q.empty()) {
		for (int i = 1; i <= k; i++) { 
			if (i != k) {
				q.push(q.front());
				q.pop();
			}
			else {
				cout << q.front();
				q.pop();
			}
		}
		if (!q.empty()) cout << ", ";
	}
	cout << ">";
}