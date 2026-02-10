#include <bits/stdc++.h>
using namespace std;

int n, nums[14], opers[4], max_ret=-2e9, min_ret = 2e9;

void go(int idx, int ret) { 
    if(idx == n) {
        max_ret = max(max_ret, ret); 
        min_ret = min(min_ret, ret);
        return;
    }
    
    for(int i=0; i<4; i++) {
        if (opers[i] > 0) {
            opers[i]--;
            int next_ret = ret;
            if (i == 0) next_ret += nums[idx];
            else if (i == 1) next_ret -= nums[idx];
            else if (i == 2) next_ret *= nums[idx];
            else if (i == 3) next_ret /= nums[idx];

            go(idx + 1, next_ret);
            opers[i]++;
        }
    }
}
int main() { 
    cin >> n;
    for(int i=0; i<n; i++) cin >> nums[i];
    for(int i=0; i<4; i++) cin >> opers[i];

    go(1, nums[0]); 

    cout << max_ret << "\n";
    cout << min_ret << "\n";
}