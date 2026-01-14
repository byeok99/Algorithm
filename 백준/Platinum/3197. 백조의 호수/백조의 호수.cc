#include <bits/stdc++.h>
using namespace std;

int r, c, visitedSwan[1504][1504], visitedWater[1504][1504], sY, sX, day;
char _map[1504][1504];
queue<pair<int, int>> water, nextWater, nextSwan, swan;
int dy[] = {0, -1, 0, 1};
int dx[] = {1, 0, -1, 0};

bool swanMove()
{
    while (swan.size())
    {
        int y, x;
        tie(y, x) = swan.front();
        swan.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= r || nx >= c || visitedSwan[ny][nx])
                continue;
            if (_map[ny][nx] == 'L')
                return true;
            if (_map[ny][nx] == 'X')
                nextSwan.push({ny, nx});
            else
                swan.push({ny, nx});

            visitedSwan[ny][nx] = 1;
        }
    }
    return false;
}

void findEdge()
{
    while (water.size())
    {
        int y, x;
        tie(y, x) = water.front();
        water.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= r || nx >= c || visitedWater[ny][nx])
                continue;

            visitedWater[ny][nx] = 1;
            if (_map[ny][nx] == 'X')
                nextWater.push({ny, nx});
            else
                water.push({ny, nx});
        }
    }
}
void metting()
{
    while (nextWater.size())
    {
        int y, x;
        tie(y, x) = nextWater.front();
        nextWater.pop();
        _map[y][x] = '.';
    }
}
int main()
{
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < c; j++)
        {
            _map[i][j] = s[j];
            if (_map[i][j] == 'L')
                sY = i, sX = j;

            if (_map[i][j] == '.' || _map[i][j] == 'L')
            {
                visitedWater[i][j] = 1;
                water.push({i, j});
            }
        }
    }

    swan.push({sY, sX});
    visitedSwan[sY][sX] = 1;
    while (true)
    {
        if (swanMove())
            break;
        findEdge();
        water = nextWater;
        swan = nextSwan;
        metting();

        while (nextSwan.size())
            nextSwan.pop();
        day++;
    }

    cout << day << "\n";
}