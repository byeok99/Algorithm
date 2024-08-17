#include <bits/stdc++.h>
using namespace std;

int dy[] = { 1, 0, -1, 0 };
int dx[] = { 0, 1, 0, -1 };

int n,cnt;
string _map[26];
bool visited[26][26];
vector<int> ret; 

void dfs(int y, int x) {
	visited[y][x] = true; 

	for (int i = 0; i < 4; i++) {
		int ny = dy[i] + y; 
		int nx = dx[i] + x; 

		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue; 
		if (_map[ny][nx] == '1' && !visited[ny][nx]) {
			cnt++;
			dfs(ny, nx);
		}
	}
}

int main() {
	cin >> n; 
	for (int i = 0; i < n; i++) {
		cin >> _map[i];
	}

	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (_map[i][j] =='1' && !visited[i][j]) {
				cnt = 1; 
				dfs(i, j);
				ret.push_back(cnt); 
			}
		}
	}
	sort(ret.begin(), ret.end());
	cout << ret.size() << "\n";
	for (int i : ret) {
		cout << i << "\n";
	}
}
