import sys
from functools import lru_cache

sys.setrecursionlimit(100000)
lim = (1<<16)
bs = [True]*lim
primes = []
n = (1<<64)-1
bs[0]=bs[1]=False

for i in range(2, lim):
    if bs[i]:
        for j in range(i*i, lim, i): bs[j] = False
        primes.append(i)

@lru_cache(maxsize=None)
def pt(b, e):
    ans = 1
    while(e>0):
        if (e&1>0):
            ans *= b
        e>>=1
        b*=b
    return ans
    return ans

s = list()

def back(i, x):
    global bs, primes, s, n
    if (i >= len(primes) or x > n): return False
    #print(i, x, "\n\n")
    #back(i+1, x)
    for j in range(4,len(bs)):
        if bs[j]: continue
        y = x * pt(primes[i], j)
        #y = x*primes[i]**j
        if ( y > n ): break
        s.append(y)
        k = i+1
        while back(k, y): k+=1
        #back(i+1,y)
    return False if j == 4 else True

#back(0, 1)

for i in range(0, lim): back(i, 1)

s.sort()
print(1)
#for j in range(0, 40): print(s[j])
for j in s: print(j)
