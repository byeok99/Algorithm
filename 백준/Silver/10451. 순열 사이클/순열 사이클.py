import sys
input = sys.stdin.readline

def dfs(u) :
    visited[u] = True

    for v in graph[u]:
        if not visited[v]:
            dfs(v)

t = int(input())
for _ in range(t):
    n = int(input())
    visited = [False] * (n+1)
    ret = 0
    graph = [[] for _ in range(n+1)]
    lst = list(map(int, input().split()))

    for i in range(1, n+1):
        graph[i].append(lst[i-1])
        graph[lst[i-1]].append(i)

    for u in range(1, n+1):
        if not visited[u]:
            dfs(u)
            ret += 1

    print(ret)
