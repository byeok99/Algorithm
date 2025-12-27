#include<bits/stdc++.h>
using namespace std;

int m, n, a, L, ret;
int main() { 
    cin >> m >> n;
    cin >> a;
    L = 1;
    for (int i=0; i<a; i++) {
        cin >> m; 
        // 바구니 안이 아니라면
        if (L > m) { 
            ret += L - m; 
            L = m;
        } else if ((L + n - 1) < m) {
            ret += m - (L + n - 1);
            L =  m - n + 1; 
        }
    }
    cout << ret << "\n";
}