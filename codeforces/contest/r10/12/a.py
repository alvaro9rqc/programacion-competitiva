for _ in range(int( input() )):
    x,y,a = map(int, input().split())
    r = (a+0.5) % (x+y)
    if (r == 0): print("YES")
    elif(r <= x): print("NO")
    else:print("YES")
