#include <bits/stdc++.h>
using namespace std;

int a, b, c, ret=0;
vector<int> v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> a >> b;
    for (int i=0; i<a; i++) {
        cin >> c;
        v.push_back(c); 
    }
    sort(v.begin(), v.end());
    for(int i=0; i < a; i++) { 
        for(int j=i+1; j<a; j++) {
            if (v[i] + v[j] == b) ret++;
        }
    }
	cout << ret << "\n";
}