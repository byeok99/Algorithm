#include <bits/stdc++.h>
using namespace std;

string s;
int main() { 
    cin >> s; 
    string ret = "YES";
    for (int i=0; i<s.length(); i++) {
        if (s[i] == 'p' && s.substr(i, 2) == "pi") i += 1; 
        else if (s[i] == 'k' && s.substr(i, 2) == "ka") i += 1; 
        else if (s[i] == 'c' && s.substr(i, 3) == "chu") i += 2; 
        else ret = "NO";
    }

    cout << ret << "\n";
}