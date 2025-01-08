import math
S = input()
n = len(S)
Q = int(input())
K = map(int, input().split())

def f(i, sw):
    if i == 1: return sw
    log = math.log(i, 2)
    if log.is_integer():
        return (int(log) % 2 == 1) ^ sw
    pot = 1<<int(log)
    return f(i % pot, not sw)

for q in K:
    g = f((q-1)//n+1, False)
    if g: print(S[(q-1) % n].swapcase(),end=" ")
    else: print(S[(q-1) % n],end=" ")
print()
