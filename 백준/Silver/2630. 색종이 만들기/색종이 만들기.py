import sys
input = sys.stdin.readline

def fun(y, x, n):
    global blue, white
    color = graph[y][x]

    for i in range(y, y + n):
        for j in range(x, x + n):
            if graph[i][j] != color:
                # 다르면 4등분 재귀
                fun(y, x, n // 2)
                fun(y, x + n // 2, n // 2)
                fun(y + n // 2, x, n // 2)
                fun(y + n // 2, x + n // 2, n // 2)
                return

    if color == 1 :
        blue += 1
    else :
        white += 1

n = int(input())
graph = [list(map(int, input().split())) for _ in range(n)]
blue, white = 0, 0

fun(0,0,n)

print(white)
print(blue)