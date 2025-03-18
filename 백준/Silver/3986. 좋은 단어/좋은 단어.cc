#include <bits/stdc++.h>
using namespace std;

int a, ret; 
string b;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> a; 
    for (int i = 0; i <a; i++)
    {
        cin >> b;
        stack<char> stk; 
        for(auto j : b) {
            if (stk.size() && stk.top() == j) stk.pop();
            else stk.push(j);
        }
        if (stk.size() == 0) ret++;
    }
    cout << ret << "\n";  
}