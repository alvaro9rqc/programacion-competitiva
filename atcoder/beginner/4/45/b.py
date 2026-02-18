n = int(input())
m = 0
l = []
for i in range(n):
    s = input()
    m=max(m,len(s))
    l.append(s)
for i in range(n):
    x = (m-len(l[i]))//2
    print("."*x+l[i]+"."*x)

