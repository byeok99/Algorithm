import sys, copy
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

dy = [0, -1, 0, 1]
dx = [1, 0, -1, 0]

def dfs(y, x):
    visited[y][x] = True

    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]

        if 0 <= ny < n and 0 <= nx < n and not visited[ny][nx] and graph[ny][nx] == prev:
            dfs(ny, nx)

n = int(input())
graph = [list(map(str, input().strip())) for _ in range(n)]

for _ in range(2):
    visited = [[False] * n for _ in range(n)]
    ret = 0
    prev = ''
    for i in range(n):
        for j in range(n):
            if not visited[i][j]:
                prev = graph[i][j]
                dfs(i, j)
                ret += 1

    for i in range(n):
        for j in range(n):
            if graph[i][j] == 'G':
                graph[i][j] = 'R'

    print(ret, end=" ")
