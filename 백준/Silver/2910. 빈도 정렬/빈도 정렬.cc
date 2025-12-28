#include <bits/stdc++.h>
using namespace std;

int n, c;
map<int, int> _map, _map_first;
vector<pair<int, int>> vec;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
    {
        return _map_first[a.second] < _map_first[b.second];
    }
    return a.first > b.first;
}

int main()
{
    cin >> n >> c;

    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        _map[input]++;
        if (_map_first[input] == 0)
            _map_first[input] = i + 1;
    }

    for (auto it : _map)
        vec.push_back({it.second, it.first});

    sort(vec.begin(), vec.end(), cmp);

    for (auto i : vec)
    {
        for (int j = 0; j < i.first; j++)
        {
            cout << i.second << " ";
        }
    }
}