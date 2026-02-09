#include <bits/stdc++.h>
using namespace std; 

int n, m, board[54][54], r, c, d, ret; 
int dy[] = {-1, 0, 1, 0}; 
int dx[] = {0, 1, 0, -1}; 

bool back(int &r, int &c, int d) {
    int nd = 0;
    if (d == 0) nd = 2;
    else if (d == 1) nd = 3;
    else if (d == 2) nd = 0; 
    else if (d == 3) nd = 1; 
    r = r + dy[nd];
    c = c + dx[nd];
    return board[r][c] == 1 ? false : true;
}

void go(int r, int c, int d) { 
    if (board[r][c] == 0) {
        board[r][c] = 2;
        ret++;
    }

    for(int i=0; i<4; i++) {
        int nd = (d + 3 - i) % 4;
        int nr = r + dy[nd]; 
        int nc = c + dx[nd];
        if (nr < 0 || nc < 0 || nr >= n || nc >= m || board[nr][nc] != 0) continue; 
        go(nr, nc, nd);
        return;
    }
    
    int temp_r=r, temp_c = c;
    if(back(temp_r, temp_c, d)) {
        go(temp_r, temp_c, d);
        return;
    }
}

int main() { 
    cin >> n >> m;
    cin >> r >> c >> d; 
    for(int i=0; i<n; i++) { 
        for(int j=0; j<m; j++) { 
            cin >> board[i][j];
        }
    }
    go(r, c, d);

    cout << ret << "\n";
}