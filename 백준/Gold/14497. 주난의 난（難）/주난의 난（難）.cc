#include <bits/stdc++.h>
using namespace std;

int n, m;
int sx, sy, ex, ey;
int visited[304][304];
char grid[304][304];

queue<pair<int, int>> q, walls;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
bool found;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    cin >> sy >> sx >> ey >> ex;
    sx--;
    sy--;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            grid[i][j] = s[j];
        }
    }

    q.push(make_pair(sy, sx));
    visited[sy][sx] = 1;

    int ret = 0;
    while (!found)
    {
        ret++;
        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();
            int y = cur.first;
            int x = cur.second;

            for (int d = 0; d < 4; d++)
            {
                int ny = y + dy[d];
                int nx = x + dx[d];

                if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx])
                    continue;

                if (grid[ny][nx] == '1')
                {
                    walls.push(make_pair(ny, nx));
                    visited[ny][nx] = 1;
                }
                else if (grid[ny][nx] == '0')
                {
                    visited[ny][nx] = 1;
                    q.push(make_pair(ny, nx));
                }
                else if (grid[ny][nx] == '#')
                {
                    found = true;
                    break;
                }
            }
        }

        while (!walls.empty())
        {
            auto cur = walls.front();
            walls.pop();
            int y = cur.first;
            int x = cur.second;
            grid[y][x] = '0';
            q.push(make_pair(y, x));
        }
    }

    cout << ret << "\n";
}