#include <bits/stdc++.h>
using namespace std; 

int n, m, x, y, k, board[21][21], orders[1001], dice[7];
int dy[] = {0, 0, -1, 1};
int dx[] = {1, -1, 0, 0};
//동쪽은 1, 서쪽은 2, 북쪽은 3, 남쪽은 4
void rotate(int dir) {
    // dice[1]: 윗면, dice[2]: 북, dice[3]: 동, dice[4]: 서, dice[5]: 남, dice[6]: 밑면
    int d1 = dice[1], d2 = dice[2], d3 = dice[3], d4 = dice[4], d5 = dice[5], d6 = dice[6];

    if (dir == 1) { // 동
        dice[1] = d4, dice[3] = d1, dice[4] = d6, dice[6] = d3;
    } else if (dir == 2) { // 서
        dice[1] = d3, dice[4] = d1, dice[6] = d4, dice[3] = d6;
    } else if (dir == 3) { // 북
        dice[1] = d5, dice[2] = d1, dice[6] = d2, dice[5] = d6;
    } else if (dir == 4) { // 남
        dice[1] = d2, dice[5] = d1, dice[6] = d5, dice[2] = d6;
    }
}

void solve() { 
    for (int i=0; i<k; i++) { 
        int dir = orders[i] - 1;
        y = y + dy[dir];
        x = x + dx[dir];
        
        if (y < 0 || x < 0 || y >= n || x >= m) { 
            y = y - dy[dir];
            x = x - dx[dir];
            continue;
        }
        rotate(dir+1);
        // cout << y << " : " << x << "\n";

        if (board[y][x] == 0) board[y][x] = dice[6];
        else {
            dice[6] = board[y][x];
            board[y][x] = 0;
        }

        cout << dice[1] << "\n";
    }
}

int main() {
    cin >> n >> m >> y >> x >> k;

    for (int i=0; i<n; i++) { 
        for (int j=0; j<m; j++) { 
            cin >> board[i][j];
        }
    }

    for(int i=0; i<k; i++) {
        cin >> orders[i];
    }
    
    solve();
}