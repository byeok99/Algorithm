#include <bits/stdc++.h>
using namespace std; 

int n, m;
string s;
char board[14][14];
bool visited[11][11][11][11];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

struct State { 
    int ry, rx, by, bx, dist;
};

void move(int &y, int &x, int &dist, int dy, int dx) {
    while(board[y + dy][x + dx] != '#' && board[y][x] != 'O') {
        y += dy;
        x += dx;
        dist += 1;
    }
}

int solve(int sry, int srx, int sby, int sbx) { 
    queue<State> q;
    q.push({sry, srx, sby, sbx, 0});
    visited[sry][srx][sby][sbx] = true;

    while(!q.empty()) { 
        State cur = q.front();
        q.pop();

        if (cur.dist >= 10) break;

        for (int i=0; i<4; i++) { 
            int nry = cur.ry, nrx = cur.rx, nby = cur.by, nbx = cur.bx;
            int r_dist = 0, b_dist = 0;

            move(nry, nrx, r_dist, dy[i], dx[i]);
            move(nby, nbx, b_dist, dy[i], dx[i]);

            if (board[nby][nbx] == 'O') continue; 
            if (board[nry][nrx] == 'O') return cur.dist + 1;

            if (nry == nby && nrx == nbx) { 
                if (r_dist > b_dist) {
                    nry -= dy[i];
                    nrx -= dx[i];
                } else { 
                    nby -= dy[i];
                    nbx -= dx[i];
                }
            }

            if (!visited[nry][nrx][nby][nbx]) {
                visited[nry][nrx][nby][nbx] = true;
                q.push({nry, nrx, nby, nbx, cur.dist + 1});
            }
        }
    }
    return -1;
}

int main() { 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int sry, srx, sby, sbx;
    cin >> n >> m;
    for(int i=0; i<n; i++) { 
        cin >> s;
        for(int j=0; j<m; j++) { 
            board[i][j] = s[j];
            if (s[j] == 'R') { 
                sry = i;
                srx = j;
            } else if (s[j] == 'B') {
                sby = i;
                sbx = j;
            }
        }
    }

    cout << solve(sry, srx, sby, sbx) << "\n";
}