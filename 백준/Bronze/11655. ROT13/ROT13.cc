#include <bits/stdc++.h> 
using namespace std; 

string s, ret;
int main() { 
    getline(cin, s);
    for(int i=0; i <s.size(); i++) { 
        int ch = s[i]; 
        if (ch >= 'a') {
            if (ch + 13 > 'z') ch = (ch + 13) - 26;
            else ch += 13; 
        } else if (ch >= 'A') { 
            if (ch + 13 > 'Z') ch =  (ch + 13) - 26;
            else ch += 13;
        }
        cout << (char)ch;
    }
}