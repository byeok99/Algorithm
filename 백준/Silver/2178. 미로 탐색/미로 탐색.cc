#include<bits/stdc++.h>
using namespace std; 

int main() { 
    int n, m, y, x; 
    int _map[101][101];
    int visited[101][101] = {{0}}; 
    int dy[] = {0, -1, 0, 1}; 
    int dx[] = {-1, 0, 1, 0}; 

    cin >> n >> m; 

    for(int i=0; i<n; i++) {
        string line; 
        cin >> line;

        for(int j=0; j<m; j++) _map[i][j] = line[j] - '0';
    }

    queue<pair<int,int>> q; 
    q.push({0,0});

    while (!q.empty()) {
        tie(y, x) = q.front(); 
        q.pop(); 

        for (int i=0; i<4; i++) { 
            int ny = y + dy[i]; 
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= n || nx >= m || _map[ny][nx] == 0 || visited[ny][nx] > 1) continue; 
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny,nx});
        }
    }

    cout << visited[n-1][m-1] + 1;

    return 0;
}