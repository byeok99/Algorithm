n = int(input())

for k in range(n, 0, -1):
    for l in range(k):
        print("*", end='')
    print()