#include <bits/stdc++.h>
using namespace std;

int n, m, a[54][54], cnt, mV, rmv, visited[54][54], comp[2504];
int dy[] = {0, -1, 0, 1};
int dx[] = {-1, 0, 1, 0};

int dfs(int y, int x) { 
    visited[y][x] = cnt; 
    int ret = 1;
    for(int i=0; i<4; i++) { 
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >=m || nx >= n || visited[ny][nx]) continue;
        if (a[y][x] & (1 << i)) continue;
        ret += dfs(ny, nx);
    }
    return ret;
}

int main() { 
    cin >> n >> m;
    
    for(int i=0; i<m; i++) { 
        for(int j=0; j<n; j++) { 
            cin >> a[i][j];
        }
    }

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) { 
            if (!visited[i][j]) {
                cnt++;
                comp[cnt] = dfs(i, j);
                mV = max(mV, comp[cnt]);
            }
        }
    }

    for(int i=0; i<m; i++) { 
        for (int j=0; j<n; j++) { 
            // cout << visited[i][j] << " ";
            for(int l=0; l<4; l++) { 
                int ny = i + dy[l];
                int nx = j + dx[l];

                if (visited[ny][nx] != visited[i][j]) { 
                    int b = visited[ny][nx];
                    int c = visited[i][j];
                    rmv = max(rmv, comp[b] + comp[c]);
                }
            }
        }
        // cout << "\n";
    }
    cout << cnt << "\n";
    cout << mV << "\n";
    cout << rmv << "\n";
    
}