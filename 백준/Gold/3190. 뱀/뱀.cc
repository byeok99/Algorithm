#include<bits/stdc++.h>
using namespace std; 

int n, k, l, board[101][101];
char dirs[10001];
int dy[] = {0, -1, 0, 1};
int dx[] = {1, 0, -1, 0};
int dummy() {
    // dir: 0우, 1 하, 2 좌, 3 상
    int y = 0, x = 0, dir = 0, cnt = 0;
    queue<pair<int,int>> snake; 
    snake.push({y, x});
    while(true) { 
        if (dirs[cnt] == 'L') dir = (dir + 1) % 4;
        else if (dirs[cnt] == 'D') dir = (dir + 3) % 4;
        y = y + dy[dir];
        x = x + dx[dir];
        
        if (y < 0 || x < 0 || y >= n || x >= n || board[y][x] == 2) break;
        
        if (board[y][x] != 1) {
            board[snake.front().first][snake.front().second] = 0;
            snake.pop();
        }
        
        board[y][x] = 2;
        snake.push({y, x});
        
        cnt++;
    }

    return cnt + 1;
}

int main() { 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cin >> k;
    for(int i=0; i<k; i++) { 
        int y, x; 
        cin >> y >> x; 
        board[y-1][x-1] = 1;
    }
    cin >> l;
    for(int i=0; i<l; i++) { 
        int time;
        char dir;
        cin >> time >> dir;
        dirs[time] = dir;
    }
    
    board[0][0] = 2;
    
    cout << dummy() << "\n";
}