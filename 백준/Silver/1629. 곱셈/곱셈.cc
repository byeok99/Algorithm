#include <bits/stdc++.h>
using namespace std; 
typedef long long ll; 


ll t(ll a, ll n, ll c) { 
    ll ret = 1; 
    while (n > 0) {
        // 홀수면
        if(n%2 == 1) {
            ret = (ret * a) % c;
            n -= 1;
        }

        a = (a * a) % c;
        n = n/2; 
    }

    return ret; 
}

ll a, b, c, ret; 
int main() { 
    cin >> a >> b >> c; 
    cout << t(a, b, c);  
}