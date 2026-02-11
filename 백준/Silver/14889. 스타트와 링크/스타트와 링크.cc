#include<bits/stdc++.h>
using namespace std; 

int n, board[24][24], min_ret = INT_MAX;
bool is_red[24];

void calcul() {
    vector<int> red, blue;
    int ret_red = 0, ret_blue = 0;

    for(int i=0; i<n; i++) { 
        if (is_red[i]) red.push_back(i);
        else blue.push_back(i);
    }

    for(int i=0; i<n/2; i++) { 
        for(int j=0; j<n/2; j++) {
            ret_red += board[red[i]][red[j]];
            ret_blue += board[blue[i]][blue[j]];
        }
    }

    min_ret = min(min_ret, abs(ret_red - ret_blue));
}
void solve(int idx, int cnt) {
    if (cnt == n/2) { 
        calcul();
        return;
    }

    for(int i=idx; i<n; i++) { 
        if (!is_red[i]) {
            is_red[i] = true;
            solve(i+1, cnt+1);
            is_red[i] = false;
        }
    }
}
int main() { 
    cin >> n; 
    for(int i=0; i<n; i++) { 
        for(int j=0; j<n; j++) { 
            cin >> board[i][j];
        }
    }

    solve(0, 0);

    cout << min_ret << "\n";
}