#include <bits/stdc++.h>
using namespace std; 

int n, k; 
int visited[200004]; 
long long cnt[200004]; 

int main() {
	cin >> n >> k; 
	if (n == k) {
		cout << 0 << "\n"; 
		cout << 1 << "\n"; 
		return 0; 
	}

	visited[n] = 1; 
	cnt[n] = 1; 
	queue<int> q; 
	q.push(n); 
	while (!q.empty()) {
		int now = q.front(); 
		q.pop();
		for (int next : {now - 1, now + 1, now * 2}) {
			if (0 <= next && next <= 200000) {
				if (!visited[next]) {
					q.push(next);
					visited[next] = visited[now] + 1;
					cnt[next] += cnt[now];
				}
				else if (visited[next] == visited[now] + 1) {
					cnt[next] += cnt[now];
				}
			}
		}
	}

	cout << visited[k] - 1 << "\n";
	cout << cnt[k];

}