#include<bits/stdc++.h> 
using namespace std; 

long long go(int a, int b, int c) { 
    if (b == 1) return a % c;

    long long ret = go(a, b/2, c); 
    ret = (ret * ret) % c;
    
    if (b % 2) ret = (ret * a) % c; 
    return ret;
}

int main() { 
    int a, b, c; 
    cin >> a >> b >> c;

    cout << go(a, b, c); 
    return 0; 
}