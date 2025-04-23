for _ in range( int(input()) ):
    n = int(input())
    a = input()
    b = input()
    pa=ia=0
    pb=ib=0
    for i in range(n):
        if a[i] == "0": continue
        if i % 2 == 0: pa+=1
        else: ia += 1
    for i in range(n):
        if b[i] == "1": continue
        if i % 2 == 0: pb+=1
        else: ib += 1
    if pa <= ib and ia <= pb: print("yes")
    else: print("no")
