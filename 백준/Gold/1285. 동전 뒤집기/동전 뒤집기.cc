#include <bits/stdc++.h>
using namespace std;

int n, ret = INT_MAX, a[44];

void go(int here) {
    if (here == n) { 
        int sum = 0;
        for (int i=0; i<n; i++) { 
            int cnt = 0;
            for (int j=0; j<n; j++) { 
                if (a[j] & (1 <<i)) cnt++;
            }
            sum += min(cnt, n-cnt);
        }
        ret = min(sum, ret);
        return;
    }
    go(here+1);
    a[here] = ~a[here];
    go(here+1);
}
int main() {
    cin >> n; 
    for(int i = 0; i < n; i++){
        string s;
		cin >> s; 
        for (int j=0; j<n; j++) { 
            if (s[j] == 'T') a[i] += 1 << j;
        }
	}

    go(0);
    
    cout << ret;
}