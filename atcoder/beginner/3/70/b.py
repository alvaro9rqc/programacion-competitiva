n = int( input() )
m = []
for i in range(n): m.append(list( map(int, input().split()) )) 
e = 1
for i in range(n):
    if e >= i+1: e = m[e-1][i]
    else: e = m[i][e-1]
print(e)
