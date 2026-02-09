#include<bits/stdc++.h>
using namespace std; 

int n, m, board[10][10], v[10][10], ret;
vector<pair<int, int>> wall_list, virus_list;
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

void dfs(int y, int x) { 
    for(int i=0; i<4; i++) { 
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if(ny < 0 || nx < 0 || ny >= n || nx >= m || board[ny][nx] == 1 || v[ny][nx]) continue;
        v[ny][nx] = true;
        dfs(ny, nx);
    }
}
int go() { 
    fill(&v[0][0], &v[0][0] + 10 * 10, false);

    for(auto virus : virus_list) {
       v[virus.first][virus.second] = true;
       dfs(virus.first, virus.second);
    }

    int cnt = 0;
    for(int i=0; i<n; i++) { 
        for(int j=0; j<m; j++) { 
            if (board[i][j] == 0 && !v[i][j]) cnt++;
        }
    }
    return cnt;
}
int main() { 
    cin >> n >> m;
    for(int i=0; i<n; i++) { 
        for(int j=0; j<m; j++) { 
            cin >> board[i][j];
            if (board[i][j] == 2) {
                virus_list.push_back({i, j});
            } 
            if (board[i][j] == 0) { 
                wall_list.push_back({i, j});
            }
        }
    }

    for(int i=0; i<wall_list.size(); i++) { 
        for(int j=0; j<i; j++) { 
            for(int l=0; l<j; l++) { 
                board[wall_list[i].first][wall_list[i].second] = 1;
                board[wall_list[j].first][wall_list[j].second] = 1;
                board[wall_list[l].first][wall_list[l].second] = 1;
                ret = max(ret, go()); 
                board[wall_list[i].first][wall_list[i].second] = 0;
                board[wall_list[j].first][wall_list[j].second] = 0;
                board[wall_list[l].first][wall_list[l].second] = 0;
                               
            }
        }
    }

    cout << ret << "\n";
}