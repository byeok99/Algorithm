s = input()

ret = sum((1 if s[i-1] != s[i] else 0) for i in range(1, len(s)))
print((ret+1)//2)