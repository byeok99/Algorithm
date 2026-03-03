#include <bits/stdc++.h>
using namespace std;

int N, M, K, a[11][11], current_nutrients[11][11], cnt;
deque<int> maps[11][11];
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};

void years() {
    // 봄 & 여름
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if (maps[i][j].empty()) continue;
            deque<int> alive;
            int dead_nutrients = 0;

            for(int age: maps[i][j]) { 
                if (current_nutrients[i][j] >= age) {
                    current_nutrients[i][j] -= age;
                    alive.push_back(age+1);
                } else { 
                    dead_nutrients += (age/2);
                }
            }
            maps[i][j] = alive;
            current_nutrients[i][j] += dead_nutrients;
        }
    }

    vector<pair<int,int>> targets;
    // 가을 
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            for(int age: maps[i][j]) {
                if(age % 5 == 0) {
                    for(int l=0; l<8; l++) {
                        int ny = i + dy[l];
                        int nx = j + dx[l];
                        
                        if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
                        targets.push_back({ny,nx});
                    }
                }
            }
        }
    }

    for(auto pos: targets) { 
        maps[pos.first][pos.second].push_front(1);
    }
    // 겨울
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            current_nutrients[i][j] += a[i][j];
        }
    }
}

int main() {
    cin >> N >> M >> K;

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> a[i][j];
        }
    }

    for(int i=0; i<M; i++) {
        int x, y, z;
        cin >> y >> x >> z;
        maps[y-1][x-1].push_back(z);
    }
    
    fill(&current_nutrients[0][0], &current_nutrients[0][0] + 11 * 11, 5);
    for(int i=0; i<K; i++) {
        years();
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if (maps[i][j].size() == 0) continue;
            cnt += maps[i][j].size();
        }
    }
    cout << cnt << "\n";
}