#include<bits/stdc++.h>
using namespace std; 

int T, N;
int memo[11];

int main() { 
    cin >> T;

    memo[1] = 1;
    memo[2] = 2;
    memo[3] = 4;

    
    while(T--) {
        cin >> N;

        for(int i=4; i<=N; i++) {
            memo[i] = memo[i-1] + memo[i-2] + memo[i-3];
        }
        cout << memo[N] << "\n";
    }
}