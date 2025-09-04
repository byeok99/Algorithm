import sys
from collections import deque
input = sys.stdin.readline

v, e, s = map(int, input().split())
graph = [[] for _ in range(v+1)]

for _ in range(e):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

for i in range(v+1):
    graph[i].sort()

def dfs(u) :
    visited[u] = True
    dfs_ret.append(u)
    for v in graph[u]:
        if not visited[v]:
            dfs(v)

def bfs(u) :
    que = deque()
    que.append(u)
    visited[u] = True
    while que:
        x = que.popleft()
        bfs_ret.append(x)

        for v in graph[x]:
            if not visited[v]:
                que.append(v)
                visited[v] = True


visited = [False] * (v+1)
dfs_ret = []
dfs(s)
visited = [False] * (v+1)
bfs_ret = []
bfs(s)
print(" ".join(map(str, dfs_ret)))
print(" ".join(map(str, bfs_ret)))