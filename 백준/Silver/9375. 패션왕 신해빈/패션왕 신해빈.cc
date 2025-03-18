#include <bits/stdc++.h> 
using namespace std; 

int main() { 
    int t, n; 
    string a, b; 
    cin >> t; 
    while (t--) { 
        map<string, int> _map;
        cin >> n; 
        for (int i=0; i <n; i++) { 
            cin >> a >> b; 
            _map[b]++; 
        }
        int ret = 1; 
        for (auto c : _map) { 
            ret *= c.second + 1;
        }

        cout << ret-1 << "\n";
    }
}