#include <bits/stdc++.h> 
using namespace std; 

int n, m, _ret; 
int _map[50][50], visited[50][50];
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

void bfs(int y, int x) {
	queue <pair<int, int>> q;
	memset(visited, 0, sizeof(visited));
	q.push({ x, y });
	visited[y][x] = 1; 
	while (q.size()) {
		tie(x, y) = q.front(); q.pop(); 

		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + x;
			int ny = dy[i] + y;

			if (nx >= m || ny >= n || nx < 0 || ny < 0) continue;
			if (visited[ny][nx]) continue;
			if (_map[ny][nx] == 0) continue; 
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ nx, ny });
			_ret = max(_ret, visited[ny][nx]);
		}
	}
}

int main() {
	cin >> n >> m; 

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char ch; 
			cin >> ch; 
			if (ch == 'L') _map[i][j] = 1;
			else _map[i][j] = 0; 
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (_map[i][j] == 1) {
				bfs(i,j);
			}
		}
	}
	cout << _ret-1; 
}