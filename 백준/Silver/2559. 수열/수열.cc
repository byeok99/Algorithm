#include <bits/stdc++.h>
using namespace std;

int a, b, temp, arr[100001], ret= -100000;
int main() {
    cin >> a >> b;
    for (int i=1; i <= a; i++) {
        cin >> temp; 
        arr[i] = arr[i-1] + temp; 
    }

    for (int i=b; i <= a; i++) { 
        ret = max(ret, arr[i] - arr[i-b]); 
    }
    cout << ret;
    return 0; 
}