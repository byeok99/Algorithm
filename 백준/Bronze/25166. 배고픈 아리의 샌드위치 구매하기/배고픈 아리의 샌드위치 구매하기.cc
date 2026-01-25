#include <bits/stdc++.h>
using namespace std; 

int s, m;

int main() { 
    cin >> s >> m;
    
    if (s < 1024) cout << "No thanks";
    else { 
        s -= 1023;
        if ((s & m) == s) cout << "Thanks";
        else cout << "Impossible";
    }
}