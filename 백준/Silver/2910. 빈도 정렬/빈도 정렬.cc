#include <bits/stdc++.h> 
using namespace std;

int n, c;
map<int, int> mp, mp_f;
typedef pair<int, int> pi;
bool cmp(pi& a, pi& b)
{
    if (a.second == b.second) 
    { 
		return mp_f[a.first] < mp_f[b.first];
	}
    return a.second > b.second;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> n >> c; 
    for (int i=0; i<n; i++) { 
        cin >> c; 
        mp[c]++; 
        if (mp_f[c] == 0) mp_f[c]  = i + 1;
    }

    vector<pi> v(mp.begin(), mp.end()); 
    sort(v.begin(), v.end(), cmp); 
    for (auto i : v) { 
        for (int j=0; j<i.second; j++) { 
            cout << i.first << " ";
        }
    } 
}