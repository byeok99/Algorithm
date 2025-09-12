import sys
from collections import deque
input = sys.stdin.readline

dx = [1, 0, -1, 0]
dy = [0, -1, 0, 1]

n, m = map(int, input().split())
graph = [list(map(int, input().strip())) for _ in range(n)]
dist = [[-1] * m for _ in range(n)]
q = deque([(0, 0)])
dist[0][0] = 1
while q:
    a, b = q.popleft()
    for i in range(4):
        ny = a + dy[i]
        nx = b + dx[i]
        if 0 <= nx < m and 0 <= ny < n and  dist[ny][nx] == -1 and graph[ny][nx] == 1 :
            dist[ny][nx] = dist[a][b] + 1
            q.append((ny, nx))

print(dist[n-1][m-1])