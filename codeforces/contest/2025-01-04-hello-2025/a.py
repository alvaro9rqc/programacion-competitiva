n = int(input())
for i in range (n):
    r, c = map(int, input().split())
    m = max(r,c)
    print(m + 1)
