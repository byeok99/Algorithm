import sys
input = sys.stdin.readline

def main():
    lst = list()
    for _ in range(9):
        lst.append(int(input()))
    lst.sort()
    
    for i in range(9):
        for j in range(i, 9):
            if sum(lst) - lst[i] - lst[j] == 100:
                for k in range(9):
                    if k == i or k == j:
                        continue
                    print(lst[k])
    
                exit(0)

if __name__ == '__main__': 
    main()
