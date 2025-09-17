import sys
from collections import deque
input = sys.stdin.readline

dy = [0, -1, 0, 1]
dx = [1, 0, -1, 0]

# 경로 저장해서 set
def bfs(y, x, visited):
    q = deque([(y,x)])
    posi = [(y,x)]
    visited[y][x] = True
    avg = graph[y][x]

    while q:
        a, b = q.popleft()

        for i in range(4):
            ny = a + dy[i]
            nx = b + dx[i]
            if 0 <= ny < n and 0 <= nx < n and  not visited[ny][nx] and l <= abs(graph[ny][nx] - graph[a][b]) <= r:
                q.append((ny,nx))
                visited[ny][nx] = True
                q.append((ny, nx))
                posi.append((ny, nx))
                avg += graph[ny][nx]

    if len(posi) == 1:
        return False
    avg = avg // len(posi)
    for a, b in posi:
        graph[a][b] = avg

    return True
ret = 0
n, l, r = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(n)]

while True:
    visited = [[False] * n for _ in range(n)]
    moved = False
    for i in range(n):
        for j in range(n):
            if not visited[i][j] :
                if bfs(i, j, visited):
                    moved = True

    if not moved:
        break
    ret += 1
print(ret)