#include<iostream> 
using namespace std; 

int T, N;
string s;
char cube[6][3][3];

void rotateFace(int p) {
   char temp[3][3];
   for(int i=0; i<3; i++) for(int j=0; j<3; j++) temp[i][j] = cube[p][i][j];
   for(int i=0; i<3; i++) for(int j=0; j<3; j++) cube[p][j][2-i] = temp[i][j];
}

void rotate(char p, char dir) { 
   int cnt = dir == '+' ? 1 : 3;
   
   while(cnt--) {
      rotateFace(p == 'U' ? 0 : p =='D' ? 1 : p == 'F' ? 2 : p == 'B' ? 3 : p == 'L' ? 4 : p == 'R' ? 5 : -1);
      char temp[3];
      if (p == 'U') {
            for (int i = 0; i < 3; i++) temp[i] = cube[3][0][i];
            for (int i = 0; i < 3; i++) cube[3][0][i] = cube[4][0][i];
            for (int i = 0; i < 3; i++) cube[4][0][i] = cube[2][0][i];
            for (int i = 0; i < 3; i++) cube[2][0][i] = cube[5][0][i];
            for (int i = 0; i < 3; i++) cube[5][0][i] = temp[i];
        } else if (p == 'D') {
            for (int i = 0; i < 3; i++) temp[i] = cube[2][2][i];
            for (int i = 0; i < 3; i++) cube[2][2][i] = cube[4][2][i];
            for (int i = 0; i < 3; i++) cube[4][2][i] = cube[3][2][i];
            for (int i = 0; i < 3; i++) cube[3][2][i] = cube[5][2][i];
            for (int i = 0; i < 3; i++) cube[5][2][i] = temp[i];
        } else if (p == 'F') {
            for (int i = 0; i < 3; i++) temp[i] = cube[0][2][i];
            for (int i = 0; i < 3; i++) cube[0][2][i] = cube[4][2 - i][2];
            for (int i = 0; i < 3; i++) cube[4][i][2] = cube[1][0][i];
            for (int i = 0; i < 3; i++) cube[1][0][i] = cube[5][2 - i][0];
            for (int i = 0; i < 3; i++) cube[5][i][0] = temp[i];
        } else if (p == 'B') {
            for (int i = 0; i < 3; i++) temp[i] = cube[0][0][i];
            for (int i = 0; i < 3; i++) cube[0][0][i] = cube[5][i][2];
            for (int i = 0; i < 3; i++) cube[5][i][2] = cube[1][2][2 - i];
            for (int i = 0; i < 3; i++) cube[1][2][2 - i] = cube[4][2 - i][0];
            for (int i = 0; i < 3; i++) cube[4][i][0] = temp[2 - i];
        } else if (p == 'L') {
            for (int i = 0; i < 3; i++) temp[i] = cube[0][i][0];
            for (int i = 0; i < 3; i++) cube[0][i][0] = cube[3][2 - i][2];
            for (int i = 0; i < 3; i++) cube[3][i][2] = cube[1][2 - i][0];
            for (int i = 0; i < 3; i++) cube[1][i][0] = cube[2][i][0];
            for (int i = 0; i < 3; i++) cube[2][i][0] = temp[i];
        } else if (p == 'R') {
            for (int i = 0; i < 3; i++) temp[i] = cube[0][i][2];
            for (int i = 0; i < 3; i++) cube[0][i][2] = cube[2][i][2];
            for (int i = 0; i < 3; i++) cube[2][i][2] = cube[1][i][2];
            for (int i = 0; i < 3; i++) cube[1][i][2] = cube[3][2 - i][0];
            for (int i = 0; i < 3; i++) cube[3][i][0] = temp[2 - i];
        }
   }
}
void init() {
   char colors[] = {'w', 'y', 'r', 'o', 'g', 'b'};
   
   for(int i=0; i<6; i++) {
      char color = colors[i];
      for(int j=0; j<3; j++) {
         for(int k=0; k<3; k++) {
            cube[i][j][k] = color;     
         }
      }
   }
}
int main() {
   cin >> T;
   
   while(T--) {
        init();
        cin >> N;
        for(int i=0; i<N; i++) {
            cin >> s;
            rotate(s[0], s[1]);
        }
        for(int j=0; j<3; j++) {
            for(int k=0; k<3; k++) {
                cout << cube[0][j][k];
            }
            cout << "\n";
        }
        
    }
}