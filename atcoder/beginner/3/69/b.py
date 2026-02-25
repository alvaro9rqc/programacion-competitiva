n = int ( input() )
ans = 0
l,r=-1,-1
for i in range(n):
    x,c = input().split()
    x = int(x)
    if (c == 'L'): 
        if l == -1: l = x
        else:
            ans += abs(l-x)
            l = x
    if (c == 'R'):
        if r == -1: r = x
        else:
            ans += abs(r-x)
            r = x
print(ans)
