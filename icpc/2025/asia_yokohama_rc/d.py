import math
s1 = input()
n = int(s1)
cif = len(s1)-1
lc = int(s1[0])
if (lc > 1):
    print(n-10**cif, 10**cif, sep='')
else:
    if (s1[1]=='0'):
        print(n-10**(cif-1), 10**(cif-1), sep='')
    else:
        print(s1[1:], 10**(cif), sep='')
