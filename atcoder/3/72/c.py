n, q = map(int, input().split())
s = input()
d = dict()
ans = 0
def erase(x):
    dx = 'A' - d[x]
    x += dx
    d.pop(x)
    d.pop(x+1)
    d.pop(x+2)
for i in range(len(s)-3):
    if (s[i] == 'A' and s[i+1] == 'B' and s[i+2] == 'C'):
        ans += 1
        d[i] = 'A'
        d[i+1]='B'
        d[i+2]='C'
for _ in range(q):
    x, c = map(int, input())
    x -= 1
    if (x in d):
        if c != d[x]:
            ans -= 1
            erase(x)
