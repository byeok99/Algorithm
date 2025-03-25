a, b = map(int, input().split())
coins = [int(input()) for _ in range(a)]
coins.sort(reverse=True)
cnt = 0
for coin in coins:
    if coin <= b :
        cnt += b // coin
        b %= coin

print(cnt)