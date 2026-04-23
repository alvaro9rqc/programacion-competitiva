#include<bits/stdc++.h>
using namespace  std;
using ll = long long;
using vi = vector<int>;
using ii = pair<int,int>;
using vl = vector<ll>;
#define rep(i, a, b) for (auto i = a; i != (b); ++i)

ll mod = 1e9+9;
template<class T, int N> struct Matrix {
    typedef Matrix M;
    array<array<T,N>,N> d{};
    M operator* (const M& m) const {
        M a;
        rep(i,0,N) rep(j,0,N)
            rep(k,0,N) a.d[i][j]+=d[i][k]*m.d[k][j]%mod, a.d[i][j]%=mod;
        return a;
    }

    array<T,N> operator* (const array<T,N>& vec) const{
        array<T,N> ret{};
        rep(i,0,N) rep(j,0,N) ret[i]+=d[i][j]*vec[j]%mod, ret[i]%=mod;
        return ret;
    }
    M operator^ (ll p) const {
        assert(p >= 0);
        M  a, b(*this);
        rep(i,0,N) a.d[i][i]=1;
        while(p) {
            if (p&1) a=a*b;
            b=b*b;
            p>>=1;
        }
        return a;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    ll n=5;
    cin>>n;
    Matrix<ll,3> a;
    Matrix<ll,3> x;
    a.d = {{
        {{2,1,0}},
        {{0,1,1}},
        {{0,0,1}}
    }};
    x.d = {{
        {{0}},
        {{1}},
        {{1}}
    }};
    a=a^n;
    a = a*x;
    //array<ll,2> b = {1,2};
    //auto c = a*b;
    //cout<<b[0]<<'\n';
    cout<<a.d[0][0]<<'\n';
//    rep(i,0,2)
 //       rep(j,0,2)
  //          cout<< a.d[i][j]<<' ';
    cout<<'\n';
}

