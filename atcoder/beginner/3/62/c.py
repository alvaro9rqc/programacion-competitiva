import sys
N = int(input())
p = [ ]
acc = []
for _ in range(N):
    l,r = map(int, input().split())
    p.append((l,r))
    if len(acc) == 0: acc.append((l,r))
    else: acc.append( ( acc[-1][0] + l,acc[-1][1] + r) )
if acc[-1][0] > 0 or acc[-1][1] < 0: 
    print("No")
    sys.exit()
g = 0
ans = [0]*N
for i in range(N-1,-1,-1):
    if i == 0:
        ans[0] = g
        break
    ans[i] = min(p[i][1], g - acc[i-1][0])
    g -= ans[i]
print("Yes")
print(*ans)
