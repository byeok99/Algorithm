n = int(input())
for i in range(n):
    n, s = input().split()

    print("".join([char * int(n)  for char in s]))

    