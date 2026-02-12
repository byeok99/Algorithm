#include<iostream> 
#include<vector>
#include<queue>
#include<tuple>
using namespace std; 

int n, l=6, r=2, sum;
vector<vector<int>> v(4);
queue<pair<int, int>> opers;

vector<int> rotate(int target, int dir) { 
   vector<int> rotated(8);
   
   // dir 1 시계, -1 반시계
   for (int i=0; i<8; i++) { 
      rotated[(i+dir+8) % 8] = v[target][i];
   }
    
   return rotated;
}
void solve(int now, int dir, vector<bool> &visited) { 
   if (now >= 4 || now < 0 || visited[now]) return;
   visited[now] = true;
   
   
   if(now+1 < 4 && v[now][r] != v[now+1][l]) solve(now+1, -dir, visited);
   if(now-1 >= 0 && v[now][l] != v[now-1][r]) solve(now-1, -dir, visited); 
   v[now] = rotate(now, dir);
}
int main() { 
   for(int i=0; i<4; i++){ 
      string s;
      cin >> s; 
      for(int j=0; j<s.size(); j++) {
         v[i].push_back(s[j] - '0');
      }
   }
   
   cin >> n; 
   for(int i=0; i<n; i++) {
      int a, b;
      cin >> a >> b;
      opers.push({a, b});
   }
   
   while(opers.size()) { 
      int target, dir; 
      tie(target, dir) = opers.front();
      opers.pop();
      
      vector<bool> visited(4);
      solve(target-1, dir, visited);      
   }
   
   for(int i=0; i<4; i++) { 
      sum += v[i][0] == 0 ? 0 : (1 << i);
   }
   
   cout << sum << "\n";
}