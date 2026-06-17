#include <string>
#include <iostream>
#include <vector>

using namespace std;
int solution(vector<vector<int>> t) {
    int answer = 0;
    for(int i=t.size()-2; i>=0; i--) {
        for(int j=0; j<t[i].size(); j++) {
            t[i][j] = max(t[i][j] + t[i+1][j], t[i][j] + t[i+1][j+1]);
        }
    }
    
    answer = t[0][0]; 
    
    return answer;
}