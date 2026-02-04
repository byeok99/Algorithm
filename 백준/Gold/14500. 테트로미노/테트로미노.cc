#include <bits/stdc++.h>
using namespace std; 

int n, m, board[501][501], ret;
bool visited[501][501];
int dy[] = {0, 0, -1, 1};
int dx[] = {-1, 1, 0, 0};

void chkT(int y, int x) { 
    for(int i=0; i<4; i++) { 
        int sum = board[y][x];
        
        for(int j=0; j<4; j++) { 
            if (i == j) continue; 
            int ny = y + dy[j];
            int nx = x + dx[j];
            if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            sum += board[ny][nx];
        }
        ret = max(ret, sum);
    }
}
void dfs(int y, int x, int cnt, int sum) { 
    if (cnt == 4) { 
        ret = max(ret, sum);
        return;
    }

    for(int i=0; i <4; i++) { 
        int ny = y + dy[i]; 
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) continue;
        visited[ny][nx] = true;
        dfs(ny, nx, cnt+1, sum+board[ny][nx]);
        visited[ny][nx] = false;
    }
}
int main() { 
    cin >> n >> m;
    for (int i=0; i<n; i++) { 
        for (int j=0; j<m; j++) { 
            cin >> board[i][j];
        }
    }

    for(int i=0; i<n; i++) { 
        for(int j=0; j<m; j++) { 
            visited[i][j] = true;
            dfs(i, j, 1, board[i][j]);
            visited[i][j] = false;
            chkT(i, j);
        }
    }

    cout << ret << "\n";
}