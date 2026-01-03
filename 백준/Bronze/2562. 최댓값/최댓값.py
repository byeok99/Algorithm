str = [];

for i in range(9):
    str.append(int(input()));

print(max(str));
print(str.index(max(str))+1);
