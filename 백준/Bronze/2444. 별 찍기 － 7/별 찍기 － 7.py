n=int(input())
for k in range(n):
    print(' '*(n-k-1)+'*'*(2*k+1))

for k in range(1, n+1):
    print(' '*k + '*'*(2*(n-k)-1))