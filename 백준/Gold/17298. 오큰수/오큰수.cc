#include <bits/stdc++.h>
using namespace std;

int n, e, now;
vector<int> vec, ret;
stack<int> stk;

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> e;
        vec.push_back(e);
    }

    reverse(vec.begin(), vec.end());

    ret.push_back(-1);
    for (int i = 1; i < vec.size(); i++)
    {
        stk.push(vec[i - 1]);
        while (!stk.empty() && stk.top() <= vec[i])
        {
            stk.pop();
        }

        if (stk.empty())
            ret.push_back(-1);
        else
            ret.push_back(stk.top());
    }

    for (int i = ret.size() - 1; i >= 0; i--)
        cout << ret[i] << " ";
}