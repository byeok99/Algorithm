#include<iostream>
#include<limits.h>
using namespace std;

int n, m, h, ret=4;
bool _map[31][11];

bool chk() { 
    for(int i=1; i<=n; i++) {
        int temp_v = i;
        for(int j=1; j<=h; j++) {
            if (_map[j][temp_v]) temp_v++;
            else if (_map[j][temp_v-1]) temp_v--;
        }
        if (temp_v != i) return false;
    }

    return true;
}

void solve(int index, int y, int x) { 
    if (index >= ret) return;
    if (chk()) {
        ret = index;
        return;
    }
    if (index == 3) return;

    for(int i=y; i<=h; i++) {
        for(int j= (i == y ? x : 1); j<n; j++) { 
            if (!_map[i][j-1] && !_map[i][j+1] && !_map[i][j]) {
                _map[i][j] = true;
                solve(index+1, i, j);
                _map[i][j] = false;
            }
        }
    }
}

int main() { 
    cin >> n >> m >> h; 
    
    for(int i=0; i<m; i++) {
        int a, b; 
        cin >> a >> b;
        _map[a][b] = true;
    }

    solve(0, 1, 1);

    cout << (ret > 3 ? -1 : ret);
}