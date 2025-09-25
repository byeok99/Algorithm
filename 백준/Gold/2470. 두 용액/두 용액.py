n = int(input())
lst = list(map(int, input().split()))
lst.sort()
l, r = 0, n-1

ret = (lst[l], lst[r])
while l < r :
    s = lst[l] + lst[r]

    if abs(s) < abs(ret[0] + ret[1]):
        ret = (lst[l], lst[r])

    if s < 0:
        l += 1
    else :
        r -= 1

print(ret[0], ret[1])