#include <bits/stdc++.h>
using namespace std; 

int r, c, k, ret, visited[10][10];
char _map[10][10];
int dy[] = {0, -1, 0, 1};
int dx[] = {1, 0, -1, 0};

void go(int y, int x, int cnt) { 
    if (cnt > k) return;
    if (cnt == k && y == 0 && x == c-1) {
        ret += 1; 
        return; 
    }

    for(int i=0; i<4; i++) { 
        int ny = y + dy[i]; 
        int nx = x + dx[i]; 

        if (ny < 0 || nx < 0 || ny >= r || nx >= c || visited[ny][nx] || _map[ny][nx] == 'T') continue;
        visited[ny][nx] = 1;
        go(ny, nx, cnt+1);
        visited[ny][nx] = 0;
    }

}
int main() { 
    cin >> r >> c >> k;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> _map[i][j];
        }
    }
    visited[r-1][0] = 1;
    go(r-1, 0, 1);

    cout << ret;
}