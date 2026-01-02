#include <bits/stdc++.h>
using namespace std;

int n, l, r, arr[54][54], ret, unionSum;
bool v[54][54], moved;
vector<pair<int, int>> unionList;
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

void dfs(int y, int x)
{
    v[y][x] = true;
    unionList.push_back({y, x});
    unionSum += arr[y][x];

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        int val = abs(arr[ny][nx] - arr[y][x]);
        if (ny < 0 || nx < 0 || ny >= n || nx >= n || v[ny][nx])
            continue;
        if (val >= l && val <= r)
        {
            dfs(ny, nx);
        }
    }
}

int main()
{
    cin >> n >> l >> r;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    while (true)
    {
        fill(&v[0][0], &v[0][0] + 54 * 54, false);
        moved = false;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!v[i][j])
                {
                    unionList.clear();
                    unionSum = 0;
                    dfs(i, j);

                    if (unionList.size() > 1)
                    {
                        moved = true;
                        for (auto e : unionList)
                        {
                            arr[e.first][e.second] = unionSum / unionList.size();
                        }
                    }
                }
            }
        }
        if (!moved)
            break;

        ret++;
    }

    cout << ret << "\n";
}