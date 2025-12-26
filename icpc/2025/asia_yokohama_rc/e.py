import math

def ff(a,b,c,k):
    f = lambda x:x*((b*x)//a)*((c*x)//a)
    xd = min(a,b,c)
    p = math.ceil(a/xd)
    d = k+1
    while(d>0):
        m = p + d//2
        if (f(m)<k): 
            p=m+1
            d-=d//2+1
        else: d//=2
    g = math.gcd(p, a)
    p//=g
    a//=g
    return a,p

def mm(m, n):
    p,q=m
    x,y=n
    if (p*y>q*x): return m
    else: return n


def solve():
    a,b,c=map(int,input().split())
    k = int(input())
    p,q = mm(ff(a,b,c,k), ff(b,c,a,k))
    p,q = mm(ff(c,a,b,k), (p,q))
    print(p,q)

tt = int(input())
for i in range(tt): solve()
