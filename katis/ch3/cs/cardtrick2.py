from collections import deque
T = int(input())
for _ in range(T):
    n = int(input())
    dq = deque()
    dq.append(n)
    for i in range(n-1, 0,-1):
        dq.appendleft(i)
        for j in range(i): dq.appendleft(dq.pop())
    print(*dq)
