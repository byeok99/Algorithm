#include <bits/stdc++.h> 
using namespace std; 

int t; 
int main() {
	cin >> t; 

	while (t--) {
		list<char> lis; 
		list<char>::iterator iter = lis.begin();
		string s;
		cin >> s; 
		
		for (char c : s) {
			if (c == '<') {
				if (iter != lis.begin()) iter--; 
			}
			else if (c == '>') {
				if (iter != lis.end()) iter++; 
			}
			else if (c == '-') {
				if (iter != lis.begin()) iter = lis.erase(--iter);
			}
			else {
				lis.insert(iter, c); 
			}
		}

		for (char c : lis) cout << c;
		cout << "\n";
	}
}