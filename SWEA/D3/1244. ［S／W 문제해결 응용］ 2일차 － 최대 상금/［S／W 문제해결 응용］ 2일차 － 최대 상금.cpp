#include<unordered_set>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std; 

int T, k, answer;
string num;
unordered_set<string> visited[11]; 

void dfs(string num, int depth) { 
	if (depth == k) {
		answer = max(answer, stoi(num));
		return;
	}
	
	if (visited[depth].count(num)) return; 
	
	visited[depth].insert(num); 
	
	for(int i=0; i<num.length()-1; i++) {
		for(int j=i+1; j<num.length(); j++) {
			swap(num[i], num[j]);
			dfs(num, depth+1);
			swap(num[i], num[j]);
		}
	}
}

int main() {
	cin >> T;
	
	for(int tc=1; tc<=T; tc++){
		cin >> num >> k;
		
		answer = 0;
		
		for( int i=0; i<=10; i++) {
			visited[i].clear();
		}
		
		dfs(num, 0);
		
		cout << "#" << tc << " " << answer << "\n";
	}
}