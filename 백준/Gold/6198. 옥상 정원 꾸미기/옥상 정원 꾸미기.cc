#include <bits/stdc++.h>
using namespace std;

long long n, ret, temp;
stack<int> stk; 

int main() {
	cin >> n; 

	for (int i = 0; i < n; i++) {
		cin >> temp; 
		if (i == 0) stk.push(temp);
		else {
			while (!stk.empty() && stk.top() <= temp) {
				stk.pop();
			}
			ret += stk.size();
			stk.push(temp); 
		}
	}

	cout << ret;
}
/*
  1. 첫 번쨰 요소는 그냥 삽입. 
  2. 두 번째 요소부터 삽입하기 전에 스택에 들어있는 요소 중 삽입하려는 요소보다 작은건 다 뺴기
  3. 개수 cnt
*/