#include <bits/stdc++.h>
using namespace std;

int n, x, ret; 
char s[15];
int main() { 
    cin >> n; 

    while(n--) {
        scanf("%s %d", s, &x);
        if (s[0] == 'a' && s[1] == 'd') ret |= (1 << x);
        else if (s[0] == 'r') ret &= ~(1 << x);
        else if (s[0] == 'c') cout << (ret & (1 << x) ? 1 : 0) << "\n";
        else if (s[0] == 't') ret ^= (1 << x);
        else if (s[0] == 'a' && s[1] == 'l') ret = (1 << 21) - 1;
        else ret = 0;
    }
}