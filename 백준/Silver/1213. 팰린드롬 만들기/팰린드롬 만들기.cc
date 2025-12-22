#include <bits/stdc++.h>
using namespace std;

string s;
int cnt[200], flag;
char mid;
string ret;
int main()
{

    cin >> s;
    for (char c : s)
        cnt[int(c)]++;

    for (int i = 'Z'; i >= 'A'; i--)
    {
        if (cnt[i])
        {
            if (cnt[i] % 2) // 홀수면
            {
                flag++;
                mid = char(i);
                cnt[i]--;
            }

            if (flag >= 2)
                break;

            if (!(cnt[i] % 2))
            {
                for (int j = 0; j < cnt[i]; j += 2)
                {
                    ret = char(i) + ret + char(i);
                }
            }
        }
    }
    if (mid)
        ret.insert(ret.begin() + ret.size() / 2, mid);
    if (flag >= 2)
        cout << "I'm Sorry Hansoo";
    else
        cout << ret;
}