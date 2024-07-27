#include <bits/stdc++.h> 
using namespace std;

const int INF = 987654321;
int n, m, sy,sx, fire[1000][1000], person[1000][1000], ret;
char _map[1000][1000];
const int dy[] = { 0, 1, 0, -1 }; 
const int dx[] = { 1, 0, -1, 0 };
queue<pair<int, int>> q; 

int main() {
	fill(&fire[0][0], &fire[0][0] + 1000 * 1000, INF);
	cin >> n >> m; 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> _map[i][j];
			if (_map[i][j] == 'J') {
				sy = i; 
				sx = j; 
			}
			else if (_map[i][j] == 'F') {
				fire[i][j] = 1; 
				q.push({ i,j }); 
			}
		}
	}

	while (q.size()) {
		int y, x; 
		tie(y, x) = q.front();
		q.pop(); 
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i]; 
			int nx = x + dx[i]; 
			if (_map[ny][nx] == '#' || fire[ny][nx] != INF) continue; 
			if (ny >= n || nx >= m || ny < 0 || nx < 0) continue; 
			fire[ny][nx] = fire[y][x] + 1; 
			q.push({ ny,nx });
		}
	}

	person[sy][sx] = 1; 
	q.push({ sy,sx });
	while (q.size()) {
		int y, x; 
		tie(y, x) = q.front(); 
		q.pop(); 
		if (y == n - 1 || x == m - 1 || x== 0 || y ==0) {
			ret = person[y][x]; 
			break;
		}
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i]; 
			int nx = x + dx[i]; 
			if (_map[ny][nx] == '#' || person[ny][nx]) continue;
			if (ny >= n || nx >= m || ny < 0 || nx < 0) continue; 
			if (fire[ny][nx] != 0 && fire[ny][nx] <= person[y][x] + 1) continue; 
			person[ny][nx] = person[y][x] + 1; 
			q.push({ ny,nx }); 
		}
	}

	if (ret != 0) cout << ret << "\n";
	else cout << "IMPOSSIBLE" << "\n";

}