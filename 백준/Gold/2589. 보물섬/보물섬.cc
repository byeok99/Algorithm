#include <bits/stdc++.h>
using namespace std;

int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

int n, m, arr[54][54], visited[54][54], _max;
vector<pair<int, int>> lList;

void bfs(int y, int x)
{
    queue<pair<int, int>> que;
    que.push({y, x});
    visited[y][x] = 1;
    while (que.size())
    {
        int y, x;
        tie(y, x) = que.front();
        que.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx] != 0 || arr[ny][nx] != 'L')
                continue;

            visited[ny][nx] = visited[y][x] + 1;
            _max = max(_max, visited[ny][nx]);
            que.push({ny, nx});
        }
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        for (int j = 0; j < m; j++)
        {
            arr[i][j] = s[j];
            if (s[j] == 'L')
                lList.push_back({i, j});
        }
    }

    for (auto l : lList)
    {
        fill(&visited[0][0], &visited[0][0] + 54 * 54, 0);
        bfs(l.first, l.second);
    }
    cout << _max - 1;
}