#include <bits/stdc++.h>
using namespace std;
using ll= long long;
using ii = pair<int,int>;
using vi = vector<int>;
using vl = vector<ll>;
#define raya cerr<<"===================="<< endl;
#define dbg(x) cerr<< #x << " = " << (x) << endl;
#define rep(i, a, b) for(auto i = a; i != (b); ++i)
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll m;
    cin >> m;

    map<ll, ll> mp;

    for (ll i = 0; i < m; ++i) {
        ll tmp;
        cin >> tmp;

        mp[tmp]++;
    }

    auto check = [&](ll n) -> bool {
        for (auto [dia, cnt] : mp) {
            ll ava = 0;

            if (dia > 2*n - 2) {
                ava = 0;
            } else if (dia < n) {
                ava = dia + 1;
            } else {
                ava = 2 * n - dia - 1;
            }

            if (ava < cnt) return false;
        }

        return true;
    };

    ll l = 1, r = ll(1e9);
    while (l < r) {
        ll m = (l+r)/2;

        if (check(m)) r = m;
        else l = m+1;
    }

    cout << l << "\n";
}



