N, M = map(int,input().split())
g = [ set() for _ in range(N) ]
ans = 0
for _ in range(M):
    u, v = map(int,input().split())
    u-=1
    v-=1
    if u == v or u in g[v]:
        ans+=1
        continue
    g[u].add(v)
    g[v].add(u)
print(ans)
