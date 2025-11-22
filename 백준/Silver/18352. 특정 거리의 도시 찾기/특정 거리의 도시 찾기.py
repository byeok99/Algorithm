import sys, heapq
input = sys.stdin.readline
INF = int(1e9)

def dijkstra(start, graph, n):
    dist = [INF] * (n+1)
    dist[start] = 0
    pq = [(0, start)]

    while pq:
        cost, now = heapq.heappop(pq)
        if cost > dist[now]:
            continue

        for nxt in graph[now]:
            new_cost = cost + 1

            if new_cost < dist[nxt]:
                dist[nxt] = new_cost
                heapq.heappush(pq, (new_cost, nxt))
    return dist

def main():
    n, m, k, x = map(int, input().split())

    graph = [[] for _ in range(n+1)]
    for _ in range(m):
        a, b = map(int, input().split())
        graph[a].append(b)

    dist = dijkstra(x, graph, n)

    flag = 0
    for i, value in enumerate(dist):
        if value == k:
            flag = 1
            print(i)
    if flag == 0:
        print(-1)
if __name__ == "__main__":
    main()