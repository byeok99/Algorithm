n = int(input())

people = []
for i in range(n):
    name, dd, mm, yy = input().split()
    people.append((int(yy),int(mm), int(dd), name))

people.sort()

print(people[-1][3])
print(people[0][3])