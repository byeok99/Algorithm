#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    
    for(int i=0; i<phone_book.size()-1; i++) {
        string first = phone_book[i];
        string second = phone_book[i+1];
        
        for(int j=0; j<first.size(); j++) {
            if (second.substr(0, first.size()) == first) return false;
        }
    }
    
    return true;
}