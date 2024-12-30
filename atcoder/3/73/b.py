d = dict()
s = input()
for i in range(len(s)):
    d[s[i]] = i
pos = d['A']
ans = 0
for i in "BCDEFGHIJKLMNOPQRSTUVWXYZ":
    ans += abs(pos - d[i])
    pos = d[i]
print(ans)
