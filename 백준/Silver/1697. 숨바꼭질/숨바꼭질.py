import sys
from collections import deque
input = sys.stdin.readline

MAX = 100000
x, k = map(int, input().split())

if x >= k:
    print(x - k)
    sys.exit(0)

dist = [-1] * (MAX+1)
dist[x] = 0
q = deque([x])

while q:
    n = q.popleft()

    if n == k:
        print(dist[n])
        break
    for nx in (n-1, n+1, n*2):
        if 0 <= nx <= MAX and dist[nx] == -1:
            dist[nx] = dist[n] + 1
            q.append(nx)