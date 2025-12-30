#include <bits/stdc++.h>
using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int n, m, a[104][104], visited[104][104]; 
vector<pair<int,int>> v;
void dfs(int y, int x) { 
    visited[y][x] = 1; 
    if (a[y][x] == 1) {
        v.push_back({y,x});
        return;
    }

    for (int i=0; i < 4; i++) { 
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (nx < 0 || nx >= m || ny < 0 || ny >= n || visited[ny][nx]) continue;
        dfs(ny,nx); 
    }
}
int main() { 
    cin >> n >> m; 
    for(int i=0; i < n; i++) {
        for(int j=0; j < m; j++) {
            cin >> a[i][j]; 
        }
    }
    int ti = 0, cnt;
    while(true) {
        cnt = 0; 
        fill(&visited[0][0], &visited[0][0] + 104 * 104 , 0);
        v.clear(); 
        dfs(0,0);
        for (pair<int, int> b : v) {
            cnt++;
            a[b.first][b.second] = 0;
        }
        bool flag = 0;
        for(int i=0; i < n; i++) {
            for(int j=0; j < m; j++) {
                if (a[i][j] == 1) flag = 1; 
            }
        }
        ti++;
        if (!flag) break; 
    }
    cout << ti << "\n" << cnt << "\n";
}