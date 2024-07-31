#include <bits/stdc++.h> 
using namespace std; 

const int MAX = 200000; 
int visited[MAX + 4], _prev[MAX+ 4]; 
int n, k;
vector<int> ret; 

int main() {
	cin >> n >> k;

	visited[n] = 1; 
	queue<int> q; 
	q.push(n); 

	while (q.size()) {
		int now = q.front();
		q.pop();
		if (now == k) {
			break;
		}

		for (int next : {now - 1, now + 1, now * 2}) {
			if (next >= MAX + 4 || next < 0 || visited[next]) continue;
			q.push(next);
			visited[next] = visited[now] + 1;
			_prev[next] = now;
		}
	}

	for (int i = k; i != n; i = _prev[i]) {
		ret.push_back(i);
	}
	ret.push_back(n);
	reverse(ret.begin(), ret.end());

	cout << visited[k] - 1 << "\n";
	for (int i : ret) cout << i << " ";
}