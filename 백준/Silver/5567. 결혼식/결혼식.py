import sys
from collections import deque
input = sys.stdin.readline

n = int(input())
m = int(input())

graph = [[] for _ in range(n+1)]
dist = [-1] * (n+1)
q = deque([1])
dist[1] = 0

ret = 0

for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

while q:
    u = q.popleft()
    if dist[u] == 2:
        continue

    for v in graph[u]:
        if dist[v] == -1:
            dist[v] = dist[u] + 1

            if dist[v] <= 2:
                ret += 1
                q.append(v)

print(ret)