N = int(input())
c = []
for x in range(N+1):
    c.append([])
    for y in range(N+1):
        c[x].append([])
        if x == 0 or y == 0:
            c[x][y]=([0]*(N+1))
        else: c[x][y]=([0])

for x in range(1,N+1):
    for y in range(1,N+1):
        c[x][y]+=list(map(int,input().split()))

#for x in range(N+1):
#    for y in range(N+1):
#        print(*c[x][y])

def hole(x,x1,y,y1,z,z1):
    return c[x1][y][z] + c[x][y1][z] + c[x][y][z1] \
        - c[x1][y1][z] - c[x1][y][z1] - c[x][y1][z1] \
        + c[x1][y1][z1]

for x in range(1,N+1):
    for y in range(1,N+1):
        for z in range(1,N+1):
            c[x][y][z] += hole(x,x-1,y,y-1,z,z-1)

Q = int(input())
for q in range(Q):
    xl,xr,yl,yr,zl,zr = map(int,input().split())
    print( c[xr][yr][zr] - hole(xr,xl-1,yr,yl-1,zr,zl-1))
