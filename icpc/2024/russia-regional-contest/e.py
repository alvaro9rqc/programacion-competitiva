from decimal import Decimal, getcontext
n,k=map(int,input().split())
l = list(map(Decimal,input().split()))
getcontext().prec = 60
l.sort()
l.reverse()
s=Decimal(0)
for i in range(len(l)): s+=l[i]/Decimal(i+1)
if(s>=k):print("YES")
else:print("NO")


