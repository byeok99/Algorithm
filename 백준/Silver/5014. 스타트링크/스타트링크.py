import sys
from collections import deque
input = sys.stdin.readline

F, S, G, U, D = map(int, input().split())
MAX = F + 1

dist = [-1] * (F + 1)
dist[S] = 0
q = deque([S])
while q :
    n = q.popleft()
    if n == G: break
    for nx in (n+U, n-D):
        if 0 < nx < MAX and dist[nx] == -1 :
            q.append(nx)
            dist[nx] = dist[n] + 1

print(dist[G] if dist[G] != -1 else "use the stairs")