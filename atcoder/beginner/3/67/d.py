n, m = map(int, input().split())
a = list(map(int, input().split()))
r = [0]
for i in range(2*n-1): 
    r.append( (r[-1] + a[i%n])%m )
b = [0]*m
for i in range(n):
    b[ r[i] ] += 1
ans = 0
for i in range(n, 2*n):
    b[ r[i-n] ] -= 1
    ans += b[ r[i] ]
    b [ r[i] ] += 1
print( ans )
