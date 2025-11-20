import sys
import heapq
input = sys.stdin.readline

dx = [0, -1, 0, 1]
dy = [1, 0, -1, 0]

def dijkstra(graph, n) :
    pq = [(0, (0,0))]
    INF = int(1e9)
    dist = [[INF] * n for _ in range(n)]
    dist[0][0] = 0

    while pq:
        cost, now = heapq.heappop(pq)
        if dist[now[0]][now[1]] < cost:
            continue

        for i in range(4):
            ny = now[0] + dy[i]
            nx = now[1] + dx[i]
            if ny < 0 or nx < 0 or ny >= n or nx >= n:
                continue
            new_cost = cost + graph[ny][nx]
            if new_cost < dist[ny][nx]:
                dist[ny][nx] = new_cost
                heapq.heappush(pq, (new_cost, (ny, nx)))

    return dist[n-1][n-1] + graph[0][0]

cnt = 1
while True:
    n = int(input())
    if n == 0: break;

    graph = []
    for _ in range(n):
        graph.append(list(map(int, input().split())))

    print(f"Problem {cnt}: {dijkstra(graph, n)}")
    cnt += 1