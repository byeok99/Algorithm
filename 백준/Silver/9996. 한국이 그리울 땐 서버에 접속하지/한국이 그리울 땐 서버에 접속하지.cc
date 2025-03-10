#include <bits/stdc++.h> 
using namespace std; 

int n; 
string s, pre, suf;  

int main() { 
    cin >> n; 
    cin >> s; 
    int pos = s.find('*'); 
    pre = s.substr(0, pos);
    suf = s.substr(pos+1);

    for(int i=0; i<n; i++) { 
        string input; 
        cin >> input; 
        if (input.size() < pre.size() + suf.size()) cout << "NE\n";
        else {
            if (pre == input.substr(0, pre.size()) && suf == input.substr(input.size() - suf.size())) cout << "DA\n";
            else cout << "NE\n";
        }
    }
}