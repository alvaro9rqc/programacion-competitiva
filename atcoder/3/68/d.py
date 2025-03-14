import sys
N, K = map(int,input().split())
sys.setrecursionlimit(3 * 10**5)
g = [ [] for _ in range(N) ]
chos = [False] * N
for _ in range(N-1):
    a,b = map(int,input().split())
    a-=1
    b-=1
    g[a].append(b)
    g[b].append(a)
ori = 0
for i in map(int, input().split()):
    chos[i-1] = True
    ori = i-1
vis = [False] * N
def dfs( v ):
    vis[v] = True
    nodes = 0
    for u in g[v]:
        if not vis[u]:
            nodes += dfs( u )
    if nodes != 0 or chos[v]: nodes +=1
    return nodes 
print(dfs(ori))


