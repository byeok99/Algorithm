import sys
import heapq

input = sys.stdin.readline
INF = int(1e9)
def dijkstra(start, graph, n, skip):
    dist = [INF] * (n+1)
    dist[start] = 0
    pq = [(0, start)]

    while pq:
        cost, now = heapq.heappop(pq)
        if dist[now] < cost:
            continue

        for nxt, w in graph[now]:
            if nxt == skip:
                continue
            new_cost = cost + w
            if new_cost < dist[nxt]:
                dist[nxt] = new_cost
                heapq.heappush(pq,(new_cost, nxt))
    
    return dist[n]

n, m = map(int, input().split())
graph = [[] for _ in range(n+1)]

for _ in range(m):
    a, b, t = map(int, input().split())
    graph[a].append((b, t))
    graph[b].append((a, t))

delay = 0
min_ret = dijkstra(1, graph, n, 0)
for i in range(2, n):
    tmp_ret = dijkstra(1, graph, n, i)
    if tmp_ret == INF:
        print(-1)
        exit(0)

    delay = max(delay, tmp_ret-min_ret)

print(delay)