#include <bits/stdc++.h>
using namespace std; 

int n, nums[100005], x, ret, chk_nums[1000005]; 
int main() {
	cin >> n; 
	for (int i = 0; i < n; i++) cin >> nums[i]; 
	cin >> x; 

	for (int i = 0; i < n; i++) {
		int temp = x - nums[i];
		if (temp > 0 &&  temp < 1000005 && chk_nums[temp]) ret++;
		chk_nums[nums[i]] = 1;
	}
	cout << ret;
}