import sys
ans = int(input())
n = int(sys.argv[1])
if (ans <= n):
    for i in range(60,-1,-1):
        if ((n&(1<<i) != 0)): break
    j = (i+1) // 2
    k = j if (i+1) %2!=0 else j-1
    while(k>=0):
        if (ans&(1<<j) > 0) != (ans&(1<<k)>0):
            print("not1", n, ans, j, k)
            sys.exit(1)
            break
        j+=1
        k-=1
else :
    print("not", n, ans)
    sys.exit(1)
print(bin(n))
print(bin(ans))
print("----------")
