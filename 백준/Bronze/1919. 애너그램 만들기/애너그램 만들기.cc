#include <bits/stdc++.h> 
using namespace std; 

string a, b;
int chk1[26], chk2[26], ret; 

int main() {
	cin >> a >> b; 

	for (int i = 0; i < a.size(); i++) {
		chk1[a[i] - 'a']++; 
	}
	for (int i = 0; i < b.size(); i++) {
		chk2[b[i] - 'a']++; 
	}

	for (int i = 0; i < 26; i++) {
		ret += abs(chk1[i] - chk2[i]); 
	}

	cout << ret;
}