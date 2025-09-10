import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

dy = [1, 1, 0, -1, -1, -1, 0, 1]
dx = [0, 1, 1, 1, 0, -1, -1, -1]

def dfs(y, x):
    visited[y][x] = True

    for i in range(8):
        nx = x + dx[i]
        ny = y + dy[i]

        if 0 <= nx < w and 0 <= ny < h and not visited[ny][nx] and graph[ny][nx] == 1:
            dfs(ny, nx)

while True:
    w, h = map(int, input().split())

    if w == 0 and h == 0:
        break

    graph = [list(map(int, input().split())) for _ in range(h)]
    visited = [[False] * w for _ in range(h)]
    ret = 0
    for i in range(h):
        for j in range(w):
            if not visited[i][j] and graph[i][j] == 1:
                ret += 1
                dfs(i, j)

    print(ret)