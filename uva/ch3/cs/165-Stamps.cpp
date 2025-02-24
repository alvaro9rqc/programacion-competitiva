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

int h, k, maxv;
map<int,int>stamp;
map<int,int>maxstamp;
map<int,int>ans;
vector<bool> check;

void dfs(int cur, int idx, int sum) {
  if (cur == h) {
    check[sum] = true;
    return;
  }
  check[sum] =true;
  for (auto i = 0; i <= idx; ++i) dfs(cur +1, idx, sum + stamp[i]);
  //prueba que pasa si se suma la primera entampa con la siguiente y así sucesivamente.
  //o sea, todas las combinaciones
}

void search(int idx) {
  if (idx == k) {
    if(maxstamp[idx-1] > maxv) {
      //si con el último valor de k se tiene un valor mayor que otra combinación
      //entonces se elije esa solución
      maxv = maxstamp[idx-1];
      ans = stamp;
    }
    return;
  }
  for (auto i = stamp[idx-1]+1; i <= maxstamp[idx-1] + 1; ++i) {
    //se escoge desde el valor de la estampa anterior y se itera hasta el máximo valor que 
    //pudo haber tenido, de lo contario, la suma mayor causaría huecos
    check.assign(200, false);
    stamp[idx] = i; //se actualiza el valor de k actualiza
    dfs(0, idx, 0);
    int j =0, num = 0;
    //for (auto j = 1; check[++j]; ++num){}
    while(check[++j]) ++num;
    maxstamp[idx] = num;
    search(idx+1);
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while(cin >> h >> k, h && k) {
    //se limpian los resultados anteriores
    stamp.clear();
    maxstamp.clear();
    maxv=0;
    stamp[0]=1;
    maxstamp[0]=h; //si la primera stamp es 1, entonces el máximo valor es h
    search(1);
    for(auto& [k,v]: ans) cout << setw(3) << v;

    cout << " ->" << setw(3) << maxv <<'\n';
  }
}


