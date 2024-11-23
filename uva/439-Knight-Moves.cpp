#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
int movx[] = {1,1,-1,-1,-2,-2,2,2};
int movy[] = {2,-2,2,-2,1,-1,1,-1};
bool chess[8][8];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string org, dest;
  while (cin >> org >> dest) {
    memset(chess, true, sizeof chess);
    queue<ii> que;
    que.emplace((int)org[1]-'1', (int)org[0] - 'a');
    int dc = dest[0] - 'a';
    int dr = (int)dest[1]-'1';
    int level = 1;
    int moves = 0;
    chess[(int)org[1]-'1'][(int)org[0] - 'a']=false;
      
    //cout << dc << ' ' << dr << '\n';
    while (! que.empty()) {
      //cout << que.size()<<'\n';
      int total = 0;
      for(int n = 0; n < level; ++n){
        auto& [i, j] = que.front(); que.pop();
        if (i == dr and j == dc) {
          cout << "To get from " << org<<" to "<<dest<<" takes "<<moves<<" knight moves.\n";
          total = 0;
          break;
        }
        for (auto m = 0; m < 8; ++m) {
          if ( 0<= i + movy[m] and i+movy[m] < 8 and
              0<= j + movx[m] and j+movx[m] < 8 and
              chess[i+movy[m]][j+movx[m]]){
            que.emplace(i+movy[m],j+movx[m]);
            chess[i+movy[m]][j+movx[m]] = false;
            total++;
          }
        }
      }
      if (total ==0) break;
      level = total;
      moves++;
    }
  }
  return 0;
}


