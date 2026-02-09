#include <bits/stdc++.h>
using namespace std;

int n, times[20], costs[20], ret;

void go(int now, int sum) {
    if (now > n + 1) return;
    if (now == n + 1) { 
        ret = max(ret, sum);
        return;
    }
    go(now + times[now], sum + costs[now]);
    go(now+1, sum);
}
int main() { 
    cin >> n; 
    for(int i=1; i<=n; i++) { 
        cin >> times[i] >> costs[i];
    }

    go(1, 0);

    cout << ret << "\n";
}