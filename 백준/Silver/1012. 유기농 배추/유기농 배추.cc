#include <bits/stdc++.h>
using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1}; 

int a[51][51], m, n, k, x, y, t; 
bool v[51][51];

void dfs(int y, int x) { 
    v[y][x] = 1; 
    for (int i=0; i<4; i++) { 
        int ny = y + dy[i]; 
        int nx = x + dx[i]; 

        if (ny >= m || nx >= n || ny < 0 || nx < 0) continue; 
        if (a[ny][nx] == 1 && !v[ny][nx]) {
            dfs(ny, nx); 
        }
    }
    return;
}

int main() { 
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int ret = 0; 
        
        fill(&a[0][0], &a[0][0] + 51 * 51, 0);
        fill(&v[0][0], &v[0][0] + 51 * 51, 0);
        cin >> n >> m >> k;

        for (int j = 0; j < k; j++)
        {
            cin >> x >> y;
            a[y][x] = 1;
        }

        for(int j=0; j<m; j++) { 
            for(k=0; k<n; k++) { 
                if (a[j][k] == 1 && !v[j][k]) {
                    ret++;
                    dfs(j,k);
                }
            }
        }
        cout << ret << "\n";
    }
}