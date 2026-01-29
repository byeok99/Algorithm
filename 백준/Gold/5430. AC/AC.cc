#include <bits/stdc++.h> 
using namespace std; 

int t, n, x;
string p, line;
int main() {
    cin >> t;

    while(t--) { 
        deque<int> dque;
        cin >> p >> n >> line;
        x = 0;
        for(char c : line) { 
            if (c == '[' || c == ']') continue;
            else if (c >= '0' && c <= '9' ) {
                x = x * 10 + c - '0';
            } else { 
                if (x > 0) dque.push_back(x);
                x = 0;
            }
        }
        if (x != 0) dque.push_back(x);
        bool error = false, rev = false;

        for (char c: p) { 
            if (c == 'R') { 
                rev = !rev;
            } else {
                if (dque.size() == 0) {
                    error = !error;
                    break;
                }

                if (rev) dque.pop_back();
                else dque.pop_front();
            }
        }

        if (error) cout << "error" << "\n";
        else {
            if (rev) reverse(dque.begin(), dque.end());
            cout << '[';
            for (int i=0; i<dque.size(); i++) { 
                cout << dque[i];
                if (i+1 != dque.size()) cout << ',';
            } 
            cout << ']' << "\n";
        }
    }
}