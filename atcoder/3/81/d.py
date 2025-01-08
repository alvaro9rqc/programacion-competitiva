from collections import deque
N = int(input())
A = list(map(int, input().split()))
def f(start):
    q = deque()
    s = set()
    count = 0
    ans = 0
    for i in range(start, N, 2):
        if (A[i] ==A[i-1]):
            if not A[i] in s:
                count += 1
                ans = max(ans, count)
                s.add(A[i])
                q.append(A[i])
            else:
                e = q.popleft()
                #print(q)
                while e != A[i]:
                    #print(":", e, "-", A[i])
                    s.remove(e)
                    count-=1
                    e = q.popleft()
                #print("ga", e)
                q.append(e)
        else:
            q.clear()
            s.clear()
            count = 0
    return ans
ans = max(f(1), f(2))
#ans = f(1)
print(ans*2)
