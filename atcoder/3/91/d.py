N, W = map(int,input().split())
grid = {}
die = {}
id = []
for _ in range(N):
    x,y = map(int,input().split())
    id.append((x,y))
    if not x in grid: 
        grid[x] = []
        die[x]={}
    grid[x].append(y)
for x, l in grid.items():
    l.sort()
t = [0]
lev = 0
f = False
while len(grid) != 0:
    for x,l in grid.items():
        if lev < len(l):
            t[-1]=max(t[-1], l[lev] -1)
            die[x][l[lev]] = len(t)-1
        else: 
            f = True
            break
    if f:
        for x, l in grid.items():
            for i in range(lev,len(l)):
                die[x][l[i]] = -1
        break
    t[-1]+=1
    t.append(t[-1])
    lev+=1

#print(die[1][1])
Q = int(input())
for _ in range(Q):
    T, a = map(int,input().split())
    idx =  die[id[a-1][0]][id[a-1][1]] 
    if len(grid) != W or t[idx] > T or idx == -1: 
        print("Yes")
    else: print("No")
