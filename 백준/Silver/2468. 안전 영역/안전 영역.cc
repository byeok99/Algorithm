#include <bits/stdc++.h> 
using namespace std;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int n, cnt = 0, max_ret=1, a[101][101];
bool visited[101][101];
void dfs(int y, int x, int num) {
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= 100 || ny >= 100) continue;
		if (a[ny][nx] > num && !visited[ny][nx]) {
			dfs(ny, nx, num);
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	for (cnt = 1; cnt < 101; cnt++) {
		fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);
		int ret = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] > cnt && !visited[i][j]) {
					ret++;
					dfs(i, j, cnt); 
				}
			}
		}
		max_ret = max(max_ret, ret);
	}

	cout << max_ret << "\n";
}