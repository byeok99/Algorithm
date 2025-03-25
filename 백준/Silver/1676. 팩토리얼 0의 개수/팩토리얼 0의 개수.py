n = int(input())
cnt = 0
while n >= 5:
    cnt += n // 5
    n = n // 5

print(cnt)