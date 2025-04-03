a, b = map(int, input().split())

def bin(n, k) :
    if k == 0 or n == k : return 1
    else : return bin(n - 1, k - 1) + bin(n-1, k)

print(bin(a, b))