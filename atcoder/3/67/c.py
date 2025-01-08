N, K = map(int, input().split())
R= list(map(int, input().split()))
st = []
sum = 0;
def bt(idx, sum):
    if (idx == N):
        if sum % K == 0:
            print(*st)
    else:
        for i in range(1, R[idx]+1):
            st.append(i)
            bt(idx+1,sum+i)
            st.pop()
bt(0,0)
