def go(n):
    d = [0] * 11 
    d[1] = 1
    d[2] = 2
    d[3] = 4
    if n < 4 : return d[n]
    for i in range(4, n+1):
        d[i] = d[i-1] + d[i-2] + d[i-3]

    return d[n]

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        print(go(int(input())))