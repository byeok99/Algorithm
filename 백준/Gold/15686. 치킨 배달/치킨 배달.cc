// 50 * 50 * 13
#include <bits/stdc++.h>
using namespace std;

int n, m, _map[54][54], ret = INT_MAX;
vector<pair<int, int>> ck_list, h_list;

// void print(vector<int> b)
// {
//     for (int i : b)
//         cout << i << " ";
//     cout << "\n";
// }

int calcualte(vector<int> b)
{
    int cnt = 0;
    for (auto home : h_list)
    {
        int _min = INT_MAX;
        for (int i : b)
        {
            auto store = ck_list[i];
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
        ret = min(calcualte(b), ret);
        return;
    }

    for (int i = start + 1; i < ck_list.size(); i++)
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
            cin >> _map[i][j];
            if (_map[i][j] == 2)
                ck_list.push_back({i, j});
            else if (_map[i][j] == 1)
                h_list.push_back({i, j});
        }
    }

    vector<int> b;
    combi(-1, b);
    cout << ret;
}