import sys
from functools import reduce
for line in sys.stdin:
    e = []
    m = []
    A = list( map(int, line.split()) )
    if len(A) == 0: break
    A.pop()
    for i in range(len(A)):
        if A[i] < 0:
            if len(e) < 2: e.append(i) 
            elif len(m) < 2: 
                m.append(e[-1])
                e[1] = i
            else:
                m[1] = e[1]
                e[1] = i
    if(len(e) == 1):
        a=1
        for i in range(0,e[0]): a*=A[i]
        b=1
        for i in range(e[0],len(A)): b*=A[i]
        print(max(a,b))
    if len(m) == 0:
        print(reduce(lambda a,b: a*b, A))
    else:
        a=b=c=1
        for i in range(0,m[0]):a*=A[i]
        for i in range(m[-1]+1,len(A)): b*=A[i]
        for i in range(m[0],m[-1]+1):c*=A[i]
        print(min(a,b)*c)

