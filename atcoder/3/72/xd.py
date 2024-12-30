n = input()
a = map(int, input().split())
ans = map(lambda x: 3 ** x, a)
print(sum( ans ))
