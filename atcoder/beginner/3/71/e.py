n = int(input())
a = list(map(int, input().split()))
m = dict()
for i in range(n):
    if not a[i] in m:
        m[a[i]] = [-1]
    m[a[i]].append(i)
ans = 0
comb = n*(n+1) // 2
for num, l in m.items():
    l.append(n)
    #print(*l)
    loc = 0
    for i in range(1, len(l)):
        d = l[i] - l[i-1] - 1
        loc += d*(d+1) // 2
    #print(loc)
    ans += comb - loc
print(ans)

