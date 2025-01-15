T = int( input() )

v = [1]
for i in range(8):
    v.append(i//2+2)
v.append(1)
for i in range(12):
    v.append(6 + i//2)
v += [12,13,13,1,12]
p=[i//2 +1 for i in range(26)]
for i in range(26,200001):
    v.append(i//2+1)
    p.append(v[-1])
for _ in range(T):
    n = int(input())
    if n &1 == 1:
        if n < 27: print(-1)
        else:
            #print(*v[0:27],end=' ')
            #print(*p[24:24+n-27])
            print(*v[0:n])
    else:
        print(*p[0:n])
