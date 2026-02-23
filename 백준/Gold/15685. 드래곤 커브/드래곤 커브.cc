#include<iostream>
#include<vector>
using namespace std; 

int N, D, G, ret;
bool board[101][101];
int dy[] = {0, -1, 0, 1};
int dx[] = {1, 0, -1, 0};

void solve(int y, int x, int dir, int g) { 
    vector<int> dirs; 
    dirs.push_back(dir);
    
    board[y][x] = true;
    y += dy[dir];
    x += dx[dir];
    board[y][x] = true;


    for(int i=0; i < g; i++) {
        for (int j = dirs.size()-1; j >= 0; j--) {
            int next_dir = (dirs[j] + 1) % 4;
            y += dy[next_dir];
            x += dx[next_dir];
            board[y][x] = true;
            dirs.push_back(next_dir);
        }
    }
}

void count_squares() { 
    for(int i=0; i<100; i++) {
        for(int j=0; j<100; j++) { 
            if (board[i][j] && board[i+1][j] && board[i][j+1] && board[i+1][j+1]) ret++;
        }
    }
}

int main() {
    cin >> N; 

    for(int i=0; i < N; i++) {
        int x=0, y=0; 
        cin>> x >> y >> D >> G;
        solve(y, x, D, G);
    }

    count_squares();

    cout << ret;
}