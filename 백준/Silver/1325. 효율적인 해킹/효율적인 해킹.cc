#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, dp[10001], _max;
vector<int> v[10001], ret;
bool visited[10001];

int dfs(int it)
{
    visited[it] = true;
    int ret = 1;

    for (auto i : v[it])
    {
        if (visited[i])
            continue;
        ret += dfs(i);
    }

    return ret;
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        v[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        fill(&visited[0], &visited[0] + 10001, false);
        ret.push_back(dfs(i));
        _max = max(ret[i - 1], _max);
    }

    for (int i = 0; i < n; i++)
    {
        if (_max == ret[i])
            cout << i + 1 << " ";
    }
}