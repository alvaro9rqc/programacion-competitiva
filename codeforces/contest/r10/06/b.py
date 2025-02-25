t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    up = 0
    down =0
    ans = 0
    for c in s:
        if c == '-': up += 1
        else: down += 1
    #print(":",up,down)
    if up % 2 == 0:
        ans = down * (up//2)**2
    else: ans = down * (up//2)*(up//2+1)
    print(ans)
