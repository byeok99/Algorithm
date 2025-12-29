// 10709
#include <bits/stdc++.h>
using namespace std;

string s;
int h, w;
int ret[101][101];
char _mp[101][101];

int main()
{
    cin >> h >> w;

    for (int i = 0; i < h; i++)
    {
        int cnt = 0;
        cin >> s;
        for (int j = 0; j < w; j++)
        {
            _mp[i][j] = s[j];

            ret[i][j] = -1;
            if (s[j] == 'c')
            {
                ret[i][j] = 0;
                cnt = 1;
            }
            else if (cnt > 0)
            {
                ret[i][j] = cnt++;
            }
        }
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cout << ret[i][j] << " ";
        }
        cout << "\n";
    }
}