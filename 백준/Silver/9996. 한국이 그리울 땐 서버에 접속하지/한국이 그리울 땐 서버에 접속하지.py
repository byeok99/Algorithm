import sys
input = sys.stdin.readline

t = int(input())
s = input().rstrip()

start, end = s.split('*')

for _ in range(t):
    s2 = input().rstrip()
    if len(start) + len(end) <= len(s2) and start == s2[:len(start)] and end == s2[-len(end):]:
        print('DA')
    else :
        print('NE')