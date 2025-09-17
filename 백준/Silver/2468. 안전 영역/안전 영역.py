from collections import deque
import sys
input = sys.stdin.readline

dy = [0, -1, 0, 1]
dx = [1, 0, -1, 0]

n = int(input())
graph = [list(map(int, input().split())) for _ in range(n)]

def bfs(y, x, k, visited):
    q = deque([(y, x)])

    while q:
        a, b = q.popleft()

        for i in range(4):
            ny = a + dy[i]
            nx = b + dx[i]
            if 0 <= ny < n and 0 <= nx < n and not visited[ny][nx] and graph[ny][nx] > k:
                visited[ny][nx] = True
                q.append((ny,nx))

_max = 0
for k in range(0, 101):
    ret = 0
    flag = False
    visited = [[False] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            if graph[i][j] > k and not visited[i][j]:
                bfs(i, j, k, visited)
                ret += 1
                flag = True

    if not flag: break
    _max = max(ret, _max)

print(_max)