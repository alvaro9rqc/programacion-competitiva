sx, sy = map(int, input().split())
tx, ty = map(int, input().split())
if (sx + sy)%2 == 0: sx+=1
if (tx + ty)%2 == 0: tx+=1

#print(":", sx,tx)
dy = abs(sy - ty)
ans = dy
dx = abs(sx - tx)
if (dy < dx): ans += (dx - dy) // 2
print(ans)
