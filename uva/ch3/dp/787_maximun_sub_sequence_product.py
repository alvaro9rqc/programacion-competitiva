import sys

for linea in sys.stdin:
    ans = 0
    a = list( map(int, linea.split()) )
    neg = pos = 0
    for n in a:
        if n == -999999: break
        if n == 0:
            ans = max(pos, ans)
            neg = pos = 0
        elif n < 0:
            nt = neg
            neg = min(n, pos*n)
            pos = max(n, nt*n)
        else:
            neg = min(n, neg*n)
            pos = max(n, pos*n)
        ans = max(ans, pos)
    if ans == 0: print(max(a))
    else: print(ans)
