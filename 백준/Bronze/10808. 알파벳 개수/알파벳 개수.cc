#include <bits/stdc++.h>
using namespace std; 

int main() { 
    vector<int> alphabet(26);
    string s; 
    cin >> s; 
    for (auto a : s) { 
        alphabet[a-'a']++;
    }

    for (auto i : alphabet) cout << i << " ";
}