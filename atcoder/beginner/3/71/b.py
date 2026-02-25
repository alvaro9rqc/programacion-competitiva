n,m = map(int, input().split())
s = set()
for i in range(m):
    f, g =  input().split()
    f = int(f)
    if not (f in s) and g == "M":
        print("Yes")
        s.add(f)
    else: print("No")
