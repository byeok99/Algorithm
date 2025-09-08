import sys
input = sys.stdin.readline

n = int(input())
tree = {}

def preorder(u):
    if not u: return
    print(u, end="")
    L, R = tree[u]
    preorder(L)
    preorder(R)

def inorder(u):
    if not u: return
    L, R = tree[u]
    inorder(L)
    print(u, end="")
    inorder(R)

def postorder(u):
    if not u: return
    L, R = tree[u]
    postorder(L)
    postorder(R)
    print(u, end="")

for _ in range(n):
    a, l, r = input().split()
    tree[a] = (l if l != '.' else None,
               r if r != '.' else None)

preorder('A')
print()
inorder('A')
print()
postorder('A')
print()
