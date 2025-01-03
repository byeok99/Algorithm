def solve(n):
    d = [0] * n * 2
    d[1] = 1

    for i in range(2, n+1):
        d[i] = d[i-1] + d[i-2]

    return d[n]

if __name__ == '__main__':
    n = int(input())
    print(solve(n))