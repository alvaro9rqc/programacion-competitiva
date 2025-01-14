n = int(input())
for _ in range(n):
    l, r= map(int,input().split())
    zer = one= r
    idx = 30
    while (l & 1 << idx) == (r & 1 << idx): idx -= 1
    if l & 1 << idx != 0:
        zer=l
        one = r
    else :
        zer=r
        one =l
    idx -= 1
    while idx >= 0: 
        zer &= ~(1<<idx)
        one |= 1 << idx
        idx -= 1
    if zer == r: r-=2
    print(zer,one,r)

