import sys
import heapq
input = sys.stdin.readline

def dijkstra(start, graph, n):
    INT = int(1e9)
    dist = [INT] * (n+1)
    dist[start] = 0
    q = [(0, start)]

    while q:
        cost, now = heapq.heappop(q)
        if dist[now] < cost:
            continue

        for nxt, w in graph[now]:
            new_cost = cost + w
            if new_cost < dist[nxt]:
                dist[nxt] = new_cost
                heapq.heappush(q, (new_cost, nxt))

    return dist

n, m, x = map(int, input().split())

graph = [[] for _ in range(n+1)]
rev_graph = [[] for _ in range(n+1)]
for _ in range(m):
    a, b, t = map(int, input().split())
    graph[a].append((b, t))
    rev_graph[b].append((a,t))
dist_to_x = dijkstra(x, graph, n)
dist_to_n = dijkstra(x, rev_graph, n)
ret = max(dist_to_x[i] + dist_to_n[i] for i in range(1, n+1))
print(ret)