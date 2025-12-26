#include<bits/stdc++.h> 
using namespace std; 

int dy[] = { -1, 0, 1,0 }; 
int dx[] = { 0, 1, 0, -1 };
int m, n, k, a[101][101]; 
bool v[101][101]; 
int cnt; 
void dfs(int y, int x) {
	v[y][x] = 1;
	cnt++;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i]; 
		int nx = x + dx[i]; 
		if (ny >= m || nx >= n || ny < 0 || nx < 0 || a[ny][nx] == 1) continue; 
		if (v[ny][nx]) continue;
		dfs(ny, nx); 
	}
}

int main() {
	cin >> m >> n >> k; 

	while(k--) {
		int x1, x2, y1, y2; 
		cin >> x1 >> y1 >> x2 >> y2; 
		
		for (int i = y1; i < y2; i++) {
			for (int j = x1; j < x2; j++) {
				a[i][j] = 1; 
			}
		}
	}

	vector<int> vec;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 0 && !v[i][j]) {
				cnt = 0; 
				dfs(i, j);
				vec.push_back(cnt);
			}
		}
	}

	sort(vec.begin(), vec.end());
	cout << vec.size() << "\n"; 
	for (int i : vec) {
		cout << i << " "; 
	}
}