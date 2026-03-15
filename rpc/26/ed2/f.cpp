#include <bits/stdc++.h>
using namespace std;
using ll= long long;
using ii = pair<int,int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
#define raya cerr<<"===================="<< endl;
#define dbg(x) cerr<< #x << " = " << (x) << endl;
#define rep(i, a, b) for(auto i = a; i != (b); ++i)
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
const ll INF = 1e18;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n, t, k;
    cin >> n >> t >> k;

    vector<pl> info;
    for (ll i = 0; i < n; ++i) {
        ll s, e;
        cin >> s >> e;

        info.emplace_back(s, e);
    }
    info.emplace_back(t, t);

    sort(all(info));

    vector<vl> dp = vector<vl>(n+1, vl(n+1, -INF));
    
    dp[0][0] = info[0].first;

    for (ll i = 0; i < n; ++i) {
        ll nnt = i+1;
        ll nt = i;
        for (ll j = i+1; j <= n; ++j) {
            if (info[j].first >= info[i].second) {
                nt = j;
                break;
            }
        }

        for (ll j = 0; j <= n; ++j) {
            // no tomo esta clase
            dp[nnt][j] = max(dp[nnt][j], dp[i][j] + info[nnt].first - info[i].first);
            // tomo esta clase
            if (j+1 <= n) 
                dp[nt][j+1] = max(dp[nt][j+1], dp[i][j] + info[nt].first - info[i].second);
        }
    }

    ll response = 0;

    for (ll i = 0; i <= n; ++i) {
        if (dp[n][i] >= k) response = i;
    }
    
    cout << response << "\n";
}



