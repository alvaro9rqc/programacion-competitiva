def minop(x,n,m):
    for i in range(30):
        if x == 0 or m+n==0:break
        if x==1 and n != 0: return 0
        if ( x & 1 == 1 ):
            if n > 0 and m <= n: 
                n -= 1
                x>>=1
            else: 
                m -= 1
                x>>=1
                x+=1
        else: 
            if m > 0: 
                m -= 1
                x>>=1
            else:
                n-=1
                x>>=1
    return x

def maxop(x,n,m):
    for i in range(30):
        if x == 0 or m+n==0:break
        if x==1 and n != 0: return 0
        if x & 1 == 0:
            x>>=1
            if n >0:n-=1
            else:m-=1
        else:
            if m > 0 and n <= m:
                m-=1
                x>>=1
                x+=1
            else:
                n-=1
                x>>=1
    return x

for _ in range(int(input())):
    x,n,m = map(int, input().split())
    low = minop(x,n,m)
    up = maxop(x,n,m)
    print(low,up)

