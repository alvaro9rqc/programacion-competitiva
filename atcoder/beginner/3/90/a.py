a = list(map(int, input().split()))
ans = 0
for idx in range(1, 5):
    if a[idx] < a[idx-1]:
        a[idx],a[idx-1] = a[idx-1], a[idx]
        ans += 1
if ans == 1: print("Yes")
else: print("No")
