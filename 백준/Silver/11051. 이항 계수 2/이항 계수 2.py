a, b = map(int, input().split())

memo = [[0] * 1001 for _ in range(1001)]

def bin(n, k):
    for i in range(n+1):
        for j in range(min(n,k)+1):
            if i==0 or i ==j :
                memo[i][j] = 1
            else :
                memo[i][j] = (memo[i-1][j-1] + memo[i-1][j]) % 10007
bin(a,b)
print(memo[a][b])