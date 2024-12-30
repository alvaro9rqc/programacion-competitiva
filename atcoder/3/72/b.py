import math
m = int( input() )
a = []
while not (m == 0 or m == 1):
    l = int( math.log(m, 3) )
    m = m - int( math.pow(3, l) )
    a.append(l)
if m == 1: a.append(0)
print(len(a))
for i in a: print(i, end=' ')
print()

