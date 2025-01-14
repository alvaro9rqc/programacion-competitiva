t = int(input())
for _ in range(t):
    n = int(input())
    mon = 0
    mi = 2
    a = list( map(int, input().split()) )
    if n == 1: 
        if a[0] > 0: print(1)
        else: print(0)
        continue
    for i in range(1,len(a)):
        if a[i] == 1: mi = 1
        if a[i] != 0 and a[i-1] == 0: mon+=1
    if a[0] != 0: mon+=1
    if mon == 0:
        print(0)
    elif mon == 1:
        print(1)
    else: print(2)


