#include <bits/stdc++.h>
using namespace std;

int n, ret;

int main() {
    cin >> n; 
    n = (~n+1) ^ n;
    for(int i=0; i<32; i++) if ((n>>i)&1) ret++;

    cout << ret;
}