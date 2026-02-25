#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int N, M;

int memo[14][140];

ll dp(int idx, int v) {
  if (idx == N-1) {
    return memo[idx][v] = M - (v + 10) + 1;
  }
  if (memo[idx][v] != -1) return memo[idx][v];
  memo[idx][v] = 0;
  for (auto i = v+10; i <= M - (N-idx-1)*10; ++i) {
    memo[idx][v] += dp(idx+1,i);
  }
  return memo[idx][v];
}

vector<int> st;

void bt(int idx, int v) {
  if (idx == N-1) {
    for (auto i = v; i <= M; ++i) {
      st[idx] = i;
      for(auto& e: st) {
        cout << e << ' ';
      }
      cout << '\n';
    }
    return;
  }
  for (auto i = v; i <= M -(N - idx - 1) * 10; ++i) {
    st[idx] = i;
    bt(idx+1,i+10);
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> M;
  st.assign(N,0);
  memset(memo, -1, sizeof(memo));
  ll x = 0;
  for (int i = 1; i <= M - (N-1)*10; ++i) {
    //cout << "i: " << i << '\n';
    x += dp(1,i);
  }
  cout << x << '\n';
  bt(0,1);
  return 0;
}


