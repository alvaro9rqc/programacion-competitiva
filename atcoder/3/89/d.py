r = int(input())
y = r-1
ans = 0
def v(x,y):
    return (x*2+1)**2 + (y*2+1)**2 <= (r*2)**2
for x in range(1,r):
    while not v(x,y): y-=1
    ans += y
print(ans*4+(r-1)*4+1)
