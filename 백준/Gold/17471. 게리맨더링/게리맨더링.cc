#include <bits/stdc++.h>
using namespace std; 

int n, ret = INT_MAX, cnt[14]; 
vector<int> a[11];

bool chk(int visited) { 
    if (visited == 0) return false; 
    
    int start_node = -1;
    for(int i=0; i<n; i++) { 
        if (visited & (1 << i)) { 
            start_node = i + 1;
            break;
        }
    }

    queue<int> q; 
    q.push(start_node);
    int current = (1 << (start_node-1));
    while(!q.empty()) {
        int curr = q.front(); 
        q.pop(); 

        for (int next: a[curr]) { 
            if (visited & (1 << (next-1)) && !(current & (1 << (next-1)))) { 
                q.push(next);
                current |= (1 << (next-1));
            }
        }
    }

    return visited == current;
}
void solve(int now, int visited) { 
    if (now == n) {
        int red_mask = visited; 
        int blue_mask = ((1 << n) - 1) & ~visited; 
        
        if (chk(red_mask) && chk(blue_mask)) {
            int red_sum = 0, blue_sum = 0;
            for (int i=0; i < n; i++) {
                if (red_mask & (1 << i)) red_sum += cnt[i];
                else blue_sum += cnt[i];
            }
            ret = min(ret, abs(red_sum - blue_sum));
        }
        return;
    }
    solve(now + 1, visited);
    solve(now + 1, visited | (1 << now)); 
}
int main() { 
    cin >> n; 
    for(int i=0; i<n; i++) { 
        cin >> cnt[i]; 
    }

    for(int i=1; i<=n; i++) { 
        int b; 
        cin >> b; 
        for(int j=1; j<=b; j++) { 
            int c; 
            cin >> c; 
            a[i].push_back(c);
        }
    }
    solve(0, 0);
    cout << (ret == INT_MAX ? -1 : ret) << "\n";
}