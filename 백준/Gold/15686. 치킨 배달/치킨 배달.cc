#include <bits/stdc++.h>
using namespace std;

int n, m, _map[54][54], ret = INT_MAX;
vector<pair<int, int>> stores, homes;
vector<vector<int>> chickenList;

int solve(vector<int> b)
{
    int cnt = 0;
    for (auto home : homes)
    {
        int _min = INT_MAX;
        for (int i : b)
        {
            auto store = stores[i];
            _min = min(abs(home.first - store.first) + abs(home.second - store.second), _min);
        }
        cnt += _min;
    }

    return cnt;
}
void combi(int start, vector<int> &b)
{
    if (b.size() == m)
    {
        chickenList.push_back(b);
        return;
    }

    for (int i = start + 1; i < stores.size(); i++)
    {
        b.push_back(i);
        combi(i, b);
        b.pop_back();
    }
    return;
}

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int posi;
            cin >> posi;
            if (posi == 2)
                stores.push_back({i, j});
            else if (posi == 1)
                homes.push_back({i, j});
        }
    }

    vector<int> b;
    combi(-1, b);

    for (auto i : chickenList)
    {
        ret = min(solve(i), ret);
    }
    cout << ret;
}
