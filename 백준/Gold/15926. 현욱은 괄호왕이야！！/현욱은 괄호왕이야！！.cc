#include <bits/stdc++.h>
using namespace std;

int n, cnt, ret, d[200004];
string s;
stack<int> stk;

int main() { 
    cin >> n; 
    cin >> s;
    for (int i=0; i<n; i++) { 
        if (s[i] == '(') stk.push(i);
        else if (stk.size()) { 
            d[i] = d[stk.top()] = 1;
            stk.pop();
        }
    }

    for (int i=0; i<n; i++) { 
        if (d[i] == 1) { 
            cnt++; 
            ret = max(ret, cnt);
        } else cnt = 0;
    }
    cout << ret << "\n";
}
// ()((((())

// 5
// (())(

// 14
// (()))()((()))(

// 12
// (()(()()(()(