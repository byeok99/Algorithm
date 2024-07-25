#include <bits/stdc++.h>
using namespace std; 

int dy[] = { 0,1, 0, -1 }; 
int dx[] = { 1, 0, -1, 0 }; 
int n, l, r, total, ret; 
int _map[50][50], visited[50][50]; 
vector<pair<int, int>> v; 

void dfs(int y, int x, vector<pair<int,int>> &v) {
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i]; 
		int nx = x + dx[i]; 

		if (ny >= n || nx >= n || ny < 0 || nx < 0) continue; 
		if (visited[ny][nx]) continue; 
		if (abs(_map[ny][nx] - _map[y][x]) >= l && abs(_map[ny][nx] - _map[y][x]) <= r) {
			v.push_back({ ny,nx }); 
			visited[ny][nx] = 1;
			total += _map[ny][nx]; 
			dfs(ny, nx, v); 
		}
	}
}

int main() {
	cin >> n >> l >> r; 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> _map[i][j]; 
		}
	}

	while(true) {
		bool flag = 0; 
		fill(&visited[0][0], &visited[0][0] + 50 * 50, 0); 
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if(!visited[i][j]) {
					v.clear();
					visited[i][j] = 1;
					v.push_back({ i,j }); 
					total = _map[i][j]; 
					dfs(i, j, v);  
					if (v.size() == 1) continue; 
					for (pair<int, int> e : v) {
						_map[e.first][e.second] = total / v.size(); 
						flag = 1; 
					}
				}
			}
		}
		if (!flag) break; 
		ret++;
	}
	cout << ret;
	return 0; 
}