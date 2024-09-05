#include <bits/stdc++.h>
using namespace std; 

string nums;
int rets[9]; 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cin >> nums; 

	for (int i = 0; i < nums.size(); i++) {
		int num = nums[i]-'0';
		rets[num]++; 
	}
	int temp = (rets[9] + rets[6] + 1) / 2;
	rets[6] = rets[9] = temp;
	cout << *max_element(rets, rets + 9);
}