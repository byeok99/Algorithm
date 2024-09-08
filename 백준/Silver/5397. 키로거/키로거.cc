#include<bits/stdc++.h>
using namespace std; 

int n;
int main() {
	cin >> n;

	while (n--) {
		list<char> lis; 
		list<char>::iterator iter = lis.begin(); 
		string input;
		cin >> input; 

		for (auto c : input) {
			if (c == '-') {
				if (iter != lis.begin()) iter = lis.erase(--iter); 
			}
			else if (c == '<') {
				if (iter != lis.begin()) iter--; 
			}
			else if (c == '>') {
				if (iter != lis.end()) iter++; 
			}
			else {
				lis.insert(iter, c);
			}
		}
		for (auto a : lis) cout << a;
		cout << '\n';
	}
}