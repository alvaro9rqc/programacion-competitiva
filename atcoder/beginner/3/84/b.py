n, r = map(int, input().split())
v = [[1600, 2799], [1200, 2399]]
for i in range(n):
    d, a = map(int, input().split())
    d -=1
    if v[d][0] <= r <= v[d][1]: r += a
print(r)
