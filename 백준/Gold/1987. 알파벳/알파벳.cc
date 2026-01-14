#include <bits/stdc++.h>
using namespace std;

int r, c, ret;
// bool visited[24][24];
bool visited[26];
char _map[24][24];
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

void dfs(int y, int x, int cnt)
{
    ret = max(ret, cnt);
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        int next = (int)(_map[ny][nx] - 'A');
        if (ny < 0 || nx < 0 || ny >= r || nx >= c || visited[next])
            continue;

        visited[next] = true;
        dfs(ny, nx, cnt + 1);
        visited[next] = false;
    }
}
int main()
{
    cin >> r >> c;

    for (int i = 0; i < r; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < c; j++)
        {
            _map[i][j] = s[j];
        }
    }
    visited[(int)_map[0][0] - 'A'] = true;
    dfs(0, 0, 1);
    cout << ret << "\n";
}