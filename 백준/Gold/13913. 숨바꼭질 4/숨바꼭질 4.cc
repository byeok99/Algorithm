#include <bits/stdc++.h>
using namespace std;

const int MAX = 200000;
int n, k, visited[MAX + 4];
int path[MAX + 4];
vector<int> v;

int main()
{
    cin >> n >> k;
    if (n == k)
    {
        cout << 0 << "\n";
        cout << n << "\n";
        return 0;
    }

    queue<int> q;
    q.push(n);
    visited[n] = 1;

    while (q.size())
    {
        int now = q.front();
        q.pop();

        for (int next : {now - 1, now + 1, now * 2})
        {
            if (next >= 0 && next <= MAX)
            {
                if (!visited[next])
                {
                    visited[next] = visited[now] + 1;
                    path[next] = now;
                    q.push(next);
                }
            }
        }
    }

    for (int i = k; i != n; i = path[i])
    {
        v.push_back(i);
    }
    v.push_back(n);

    reverse(v.begin(), v.end());

    cout << visited[k] - 1 << "\n";
    for (auto i : v)
        cout << i << " ";
}