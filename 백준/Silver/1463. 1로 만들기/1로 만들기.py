def go(n):
    d = [0 for i in range(3 * n +1)]

    for i in range(2, n+1):
        d[i] = d[i-1]+1
        if i%2==0:
            d[i] = min(d[i],d[i//2]+1)

        if i%3==0:
            d[i] = min(d[i],d[i//3]+1)

    return d[n]

if __name__ == "__main__":
    n = int(input())
    print(go(n))