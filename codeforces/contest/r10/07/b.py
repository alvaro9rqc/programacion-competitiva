T = int(input())
for _ in range(T):
    n = int(input())
    if n == 1: print(-1)
    else:
        print("2 1 ",end="")
        for i in range(3,n+1):
            print(i,"",end="")
        print()
