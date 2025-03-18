#include <bits/stdc++.h>
using namespace std;

int main() { 
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, a, b, arr[100001];
    cin >> n; 

    for (int i=1; i <= n; i++) { 
        cin >> a; 
        arr[i] = arr[i-1] + a; 
    }

    cin >> n; 
    for (int i=1; i <=n; i++) { 
        cin >> a >> b; 
        cout << arr[b] - arr[a-1] << "\n";
    }
}