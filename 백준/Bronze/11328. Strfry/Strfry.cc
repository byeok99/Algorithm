#include<bits/stdc++.h> 
using namespace std;

int n;
string a, b;
int main() {
	cin >> n; 

	for (int i = 0; i < n; i++) {
		cin >> a >> b; 
		sort(a.begin(), a.end()); 
		sort(b.begin(), b.end()); 

		if (a != b)	cout << "Impossible" << "\n";
		else cout << "Possible" << "\n";
	}
}