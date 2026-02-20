#include<bits/stdc++.h>
using namespace std; 

int n, m, a[10][10], ret=INT_MAX;
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

struct CCTV { 
    int y, x, type;
};
vector<CCTV> cctvs;

void watch(int y, int x, int dir, int tmp[10][10]) {
    dir %= 4; 
    while (true) { 
        y += dy[dir];
        x += dx[dir];
        if (y < 0 || y >= n || x < 0 || x >= m || tmp[y][x] == 6) break; 
        if (tmp[y][x] == 0) tmp[y][x] = -1;
    }
}

void solve(int idx, int cBoard[10][10]) { 
    if (idx == cctvs.size()) { 
        int cnt =0;
        for (int i=0; i<n; i++) { 
            for(int j=0; j<m; j++) { 
                if (cBoard[i][j] == 0) cnt++;
            }
        }
        ret = min(ret, cnt);
        return;
    }
    
    int y = cctvs[idx].y;
    int x = cctvs[idx].x;
    int type = cctvs[idx].type;

    for(int dir=0; dir<4; dir++) { 
        int nextBoard[10][10];

        for(int i=0; i<n; i++) { 
            for(int j=0; j<m; j++) nextBoard[i][j] = cBoard[i][j];
        }

        if(type == 1) {
            watch(y, x, dir, nextBoard);
        } else if (type == 2) {
            watch(y, x, dir, nextBoard);
            watch(y, x, dir+2, nextBoard);
        } else if (type == 3) { 
            watch(y, x, dir, nextBoard);
            watch(y, x, dir+1, nextBoard);
        } else if (type == 4) {
            watch(y, x, dir, nextBoard);
            watch(y, x, dir + 1, nextBoard);
            watch(y, x, dir + 2, nextBoard);
        } else if (type == 5) { 
            watch(y, x, 0, nextBoard);
            watch(y, x, 1, nextBoard);
            watch(y, x, 2, nextBoard);
            watch(y, x, 3, nextBoard);
        }

        solve(idx + 1, nextBoard);
        if(type == 5) break;
    }

}
int main() { 
    cin >> n >> m;
    for(int i=0; i<n; i++) { 
        for(int j=0; j<m; j++) {
            cin >> a[i][j];
            if(a[i][j] >= 1 && a[i][j] <= 5) cctvs.push_back({i, j, a[i][j]});
        }
    }
    
    solve(0, a);
    cout << ret;
}