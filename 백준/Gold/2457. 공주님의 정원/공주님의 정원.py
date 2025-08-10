n = int(input())
days = []

for _ in range(n):
    day = list(map(int, input().split()))

    days.append((day[0] * 100 + day[1], day[2] * 100 + day[3]))

days.sort()
end_date = 301
cnt = 0

while (days):
    if end_date >= 1201 or days[0][0] > end_date:
        break

    temp_end_date = -1
    for _ in range(len(days)):
        if days[0][0] <= end_date:
            if temp_end_date <= days[0][1]:
                temp_end_date = days[0][1]
            days.remove(days[0])
        else :
            break

    end_date = temp_end_date
    cnt += 1
if end_date < 1201:
    print(0)
else:
    print(cnt)