n = int(input())

plus = []
minus = []

ret = 0
for i in range(n) :
    num = int(input())
    if num > 1:
        plus.append(num)
    elif num <= 0:
        minus.append(num)
    else:
        ret += num

plus.sort(reverse=True)
minus.sort()

for i in range(0, len(plus), 2):
    if i+1 >= len(plus):
        ret += plus[i]
    else :
        ret += plus[i] * plus[i+1]

for i in range(0, len(minus), 2):
    if i+1 >= len(minus):
        ret += minus[i]
    else :
        ret += minus[i] * minus[i+1]

print(ret)