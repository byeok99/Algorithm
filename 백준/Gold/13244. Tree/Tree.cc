#include<bits/stdc++.h>
using namespace std;

int t, n, m, visited[1004], cnt;
vector<int> vec[1004];

void dfs(int here) { 
    visited[here] = 1;
    for(int there : vec[here]) { 
        if (!visited[there]) dfs(there);
    }
    return;
}

int main() { 
    cin >> t;

    while(t--) { 
        for (int i=0; i<1004; i++) vec[i].clear();
        fill(visited, visited + 1004, 0);
        cin >> n;
        cin >> m;
        cnt = 0;
        for (int i=0; i<m; i++) { 
            int a, b =0;
            cin >> a >> b;
            vec[a].push_back(b);
            vec[b].push_back(a);
        }

        for (int i=1; i <= n; i++) { 
            if (!visited[i]) { 
                dfs(i);
                cnt++;
            }
        }

        if (m == n - 1 && cnt == 1) cout << "tree" << "\n";
        else  cout << "graph" << "\n";
    }
}