#include <bits/stdc++.h>
using namespace std;

int n;
char a[10];
bool c[10];
vector<string> ret;

bool chk(int a, int b, char op)
{
    if (op == '>' && a > b)
        return a > b;
    if (op == '<' && a < b)
        return a < b;
    return false;
}

void go(int now, string num)
{
    if (now == n + 1)
    {
        ret.push_back(num);
        return;
    }

    for (int i = 0; i < 10; i++)
    {
        if (c[i])
            continue;

        if (now == 0 || chk(num.back() - '0', i, a[now - 1]))
        {
            c[i] = true;
            go(now + 1, num + to_string(i));
            c[i] = false;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    go(0, "");

    sort(ret.begin(), ret.end());
    cout << ret[ret.size() - 1] << "\n";
    cout << ret[0] << "\n";
}