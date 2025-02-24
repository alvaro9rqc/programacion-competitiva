#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

typedef pair<ll, ll> ll_p; 
typedef tuple<ll, ll, ll> ll_t; 
typedef vector<ll> vll;
typedef vector<ll_p> vll_p;   
typedef vector<ll_t> vll_t;

vi ans(8,0);

vector<bool> row(8, true);
vector<bool> upd(15, true);
vector<bool> dod(15, true);
ll n;
int ro, co; 
void backtraking(int c) {
  if(c==8) {
    printf("%2lld      %d %d %d %d %d %d %d %d\n",
        ++n,
        ans[0]+1,
        ans[1]+1,
        ans[2]+1,
        ans[3]+1,
        ans[4]+1,
        ans[5]+1,
        ans[6]+1,
        ans[7]+1
        );
    return;
  }
  if(c==co) {
    backtraking(c+1);
    return;
  }
  for (auto r = 0; r < 8; ++r) {
    if(row[r] and upd[r+c] and dod[r+7-c]) {
      row[r] = false;
      upd[r+c]=false;
      dod[r+7-c]=false;
      ans[c]=r;
      backtraking(c+1);
      row[r] = true;
      upd[r+c]=true;
      dod[r+7-c]=true;
    }
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T; cin >> T;
  while(T--) {
    cin >> ro >> co;
    --ro,--co;
    row[ro]=false;
    upd[ro+co]=false;
    dod[ro+7-co]=false;
    n = 0;
    ans[co]=ro;
    printf("SOLN       COLUMN\n");
    printf(" #      1 2 3 4 5 6 7 8\n\n");
    backtraking(0);
    row[ro]=      true;
    upd[ro+co]=   true;
    dod[ro+7-co]= true;
    if (T) printf("\n");
  }
}


