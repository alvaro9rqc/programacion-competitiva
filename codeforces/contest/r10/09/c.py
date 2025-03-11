T = int(input())
def ist(a,b,c):
    return (a + b > c) and (a + c > b) and (b+c>a)
for _ in range(T):
    n = int(input())
    if(n < 4): print(-1)
    else:
        idx = 30
        b = n
        e = 0
        while (idx >= 0):
            if (b&(1<<idx) > 0 and n&(1<<idx) > 0):
                if e == 0: e+=1
                if e == 1: 
                    b ^= 1<<idx
                    e +=1
            elif (e == 2 and b&(1<<idx) == 0 and n&(1<<idx)==0):
                b |= 1 << idx
                break
            idx -=1
        if (ist(n, b, b^n)): print(b)
        else: print(-1)
