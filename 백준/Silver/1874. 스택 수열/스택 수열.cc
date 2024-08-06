#include <bits/stdc++.h>
using namespace std;

int n, temp; 
vector<char> ret;
stack<int> stk; 

int main() {
	cin.tie(0);
	cout.tie(0); 
	ios::sync_with_stdio(false); 
	
	cin >> n; 
	
	int num = 1; 
	for (int i = 0; i < n; i++) {
		cin >> temp; 

		if (!stk.empty() && stk.top() == temp) {
			stk.pop(); 
			ret.push_back('-');
		} 
		else if (num <= temp) {
			while (num <= temp) {
				stk.push(num++);
				ret.push_back('+');
			}
			stk.pop();
			ret.push_back('-');
		}
		else if (!stk.empty() && stk.top() > temp) {
			cout << "NO";
			return 0;
		}
	}

	for (char a : ret) cout << a << "\n";
}