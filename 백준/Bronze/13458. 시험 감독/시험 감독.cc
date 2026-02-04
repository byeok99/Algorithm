#include <bits/stdc++.h>
using namespace std; 

int n, a[1000001], b, c;
long long ret;
int main() { 
    cin >> n; 
    for(int i=0; i<n; i++) { 
        cin >> a[i];
    }
    cin >> b >> c;
    for (int i=0; i<n; i++) {
        if (a[i] < b) ret += 1;
        else ret += (a[i] - b) / c + ((a[i] - b) % c == 0 ? 0 : 1) + 1;
    }
    cout << ret << "\n";
}