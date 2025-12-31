#include <bits/stdc++.h>
using namespace std;

int a, b, root, cnt; 
vector<int> v[55]; 

int dfs(int here) { 
    int ret=0;
    int child=0; 
    for(int i : v[here]) { 
        if (b == i) continue; 
        ret += dfs(i); 
        child++;
    }
    if (child == 0) return 1;
    return ret; 

}
int main() { 
    cin >> a;

    for(int i=0; i < a; i++) {
        cin >> b;
        if (b == -1) root = i;
        else v[b].push_back(i); 
    }
    cin >> b;
    if (b == root) {
        cout << 0 << "\n";return 0;
    }
    
    cout << dfs(root) << "\n"; 
}