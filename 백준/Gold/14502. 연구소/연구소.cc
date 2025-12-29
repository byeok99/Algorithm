#include <bits/stdc++.h>
using namespace std;

int n, m, a[10][10], visited[10][10];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1}; 
typedef pair<int, int> pi;
vector<pi> v; 
void dfs(int y, int x) {
    visited[y][x] = 1;
    for(int i=0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (nx < 0 || ny < 0 || ny >= n  || nx >= m) continue;
        if (a[ny][nx] == 0 && !visited[ny][nx]) {
            dfs(ny,nx); 
        }
    }
}

int count() { 
	fill(&visited[0][0], &visited[0][0] + 10 * 10, 0);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (a[i][j] == 2) dfs(i,j); 
        }
    }
    int cnt = 0; 
    for (int i=0; i < n; i++) {
        for (int j=0; j < m; j++) {
            if (!visited[i][j] && a[i][j] == 0) cnt++; 
        }
    }

    return cnt;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m; 
    for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> a[i][j];
			if(!a[i][j]) v.push_back(pi(i, j));
		}
	}

    int cnt=0; 
    for (int i=0; i < v.size(); i++) {
        for (int j=0; j < i; j++) {
            for (int k=0; k < j; k++) {
                a[v[i].first][v[i].second] = a[v[j].first][v[j].second] = a[v[k].first][v[k].second] = 1; 
                cnt = max(cnt, count()); 
                a[v[i].first][v[i].second] = a[v[j].first][v[j].second] = a[v[k].first][v[k].second] = 0;
            }
        }
    }
    cout << cnt << "\n";
}