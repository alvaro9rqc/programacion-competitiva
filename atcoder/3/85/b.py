h,w,x,y= map(int, input().split() )
x-=1
y-=1
g =[]
for r in range(h):
    g.append(input())
s = set()
T = input()
m = {
    'U': [-1,0],
    'D': [1,0],
    'L': [0,-1],
    'R': [0,1],
}
houses = set()
for c in T:
    nx =x+ m[c][0]
    ny =y+ m[c][1]
    if not g[nx][ny] == '#':
        x=nx
        y=ny
        if g[x][y]=='@': houses.add((x,y))
print(x+1,y+1,len(houses))
