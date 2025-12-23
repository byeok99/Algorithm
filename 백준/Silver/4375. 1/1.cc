#include<bits/stdc++.h>
using namespace std;

int a;  
int main() {
    while(scanf("%d", &a) != EOF) { 
        int b = 1, len = 1; 
        while (true) {
            if (b % a == 0) { 
                printf("%d\n", len);
                break;
            } else { 
                b = (10 * b) + 1;
                b %= a;
                len++;
            }
        }
    }
}