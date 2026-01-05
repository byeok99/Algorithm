#include <bits/stdc++.h>
using namespace std;

int r, c, sY, sX, ret, visited[1004][1004], person[1004][1004];
queue<pair<int, int>> q;
char _map[1004][1004];
string s;

int dy[] = {0, -1, 0, 1};
int dx[] = {1, 0, -1, 0};

int main()
{
    cin >> r >> c;

    for (int i = 0; i < r; i++)
    {
        cin >> s;
        for (int j = 0; j < c; j++)
        {
            _map[i][j] = s[j];
            if (s[j] == 'J')
            {
                sY = i;
                sX = j;
                person[i][j] = 1;
            }
            else if (s[j] == 'F')
            {
                q.push({i, j});
                visited[i][j] = 1;
            }
        }
    }

    while (q.size())
    {
        int y, x;
        tie(y, x) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny, nx;
            ny = y + dy[i];
            nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= r || nx >= c || visited[ny][nx] || _map[ny][nx] == '#')
                continue;

            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }

    q.push({sY, sX});
    while (q.size())
    {
        int y, x;
        tie(y, x) = q.front();
        q.pop();

        if (y == 0 || x == 0 || y == r - 1 || x == c - 1)
        {
            ret = person[y][x];
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int ny, nx;
            ny = y + dy[i];
            nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= r || nx >= c || _map[ny][nx] == '#' || person[ny][nx])
                continue;
            if (visited[ny][nx] <= person[y][x] + 1 && visited[ny][nx] != 0)
                continue;
            person[ny][nx] = person[y][x] + 1;
            q.push({ny, nx});
        }
    }

    if (ret != 0)
        cout << ret << "\n";
    else
        cout << "IMPOSSIBLE" << "\n";
}