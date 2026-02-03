#include<bits/stdc++.h>
using namespace std; 

int n, ret;
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

vector<vector<int>> move(vector<vector<int>> b, int dir) {
    for(int i=0; i<n; i++) { 
        // 0: 상, 1: 하, 2: 우, 3: 좌
        vector<int> items;
        for(int j=0; j<n; j++) { 
            int row = dir < 2 ? j : i;
            int col = dir < 2 ? i : j;
            if (b[row][col] != 0) items.push_back(b[row][col]);
        }

        if (dir == 0 || dir == 2) reverse(items.begin(), items.end());

        vector<int> merged;
        for(int j=0; j<items.size(); j++) { 
            if (items.size() > j+1 && items[j+1] == items[j]) {
                merged.push_back(items[j] * 2);
                j++;
            } else merged.push_back(items[j]);
        }
        
        while(merged.size() < n) merged.push_back(0);
        if (dir == 0 || dir == 2) reverse(items.begin(), items.end()); 

        for(int j=0; j<n; j++) { 
            int row = dir < 2 ? j : i;
            int col = dir < 2 ? i : j;
            b[row][col] = merged[j];
        }
    }
    return b;
}
void bfs(vector<vector<int>> b, int cnt) { 
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) { 
            ret = max(ret, b[i][j]);
        }
    }
    if(cnt == 5) return;

    for(int i=0; i<4; i++) { 
        bfs(move(b, i), cnt+1);
    }
}
int main() { 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n));
    for(int i=0; i<n; i++) { 
        for(int j=0; j<n; j++) { 
            cin >> board[i][j];
        }
    }
    bfs(board, 0);

    cout << ret;
}