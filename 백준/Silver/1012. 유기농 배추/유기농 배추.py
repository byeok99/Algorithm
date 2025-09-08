import sys
from collections import deque
input = sys.stdin.readline

t = int(input())
dy = [1, 0, -1, 0]
dx = [0, 1, 0, -1]

for _ in range(t):
    m, n, k = map(int, input().split())

    visited = [[False] * m for _ in range(n)]
    arr = [[0] * m for _ in range(n)]

    for _ in range(k):
        x, y = map(int, input().split())
        arr[y][x] = 1

    que = deque()
    ret = 0
    for i in range(n):
        for j in range(m):
            if arr[i][j] == 1 and not visited[i][j]:
                ret += 1
                que.append((i, j))

                while que:
                    y, x = que.popleft()

                    for l in range(4):
                        nx = x + dx[l]
                        ny = y + dy[l]
                        if 0 <= ny < n and 0 <= nx < m and arr[ny][nx] == 1 and not visited[ny][nx] :
                            visited[ny][nx] = True
                            que.append((ny, nx))

    print(ret)