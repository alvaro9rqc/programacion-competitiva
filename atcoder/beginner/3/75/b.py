import math
n = int( input() )
x = 0
y = 0
ans = 0
def dist(a, b):
    return math.sqrt( (a - x)**2 + (b - y)**2 )

for i in range(n):
    a, b = map(int, input().split())
    ans += dist(a, b)
    x = a
    y = b
t1 = x
t2 = y
x = y = 0
ans += dist(t1, t2)
print(ans)
