#include<bits/stdc++.h>
using namespace std;

list<char> lis; 
string s; 
int n;
char temp, temp2;
int main() {
	cin >> s; 
	cin >> n;
	for (char a : s) lis.push_back(a);
	list<char>::iterator it = lis.end();

	for (int i = 0; i < n; i++) {
		cin >> temp; 
		if (temp == 'L') {
			if (it != lis.begin()) it--;
		}
		else if (temp == 'D') {
			if (it != lis.end()) it++;
		}
		else if (temp == 'B') {
			if (it != lis.begin()) it = lis.erase(--it);
		}
		else if (temp == 'P') {
			cin >> temp2;
			lis.insert(it, temp2);
		}
	}

	for (char a : lis) cout << a; 
}