#include <bits/stdc++.h> 
using namespace std;
int main () {
  //Really, I didn't try it, but I read the solution in Halims' book
  //TIP: Complete Search
  //I couldn't do it, but now I know how to solve it, so i need to try again after a while.
  //Now it's been a long time, I can do it
  int a, b, c, N;
  cin >> N; 
  while (N--) {
    cin >> a >> b >> c;
    bool nof = true;
    for (int x = 1; x*x <= c && nof; ++x ) 
      for (int y = 1; y*y <= c - x*x && nof; ++y)
        for (int z = 1; z <= c - x*x - y*y && nof; ++z) {
          if ( 
              (x*x + y*y + z*z == c) &&
              (x*y*z == b) &&
              (x+y+z == a)
             )
          {
            cout << x << ' ' << y << ' ' << z << '\n';
            nof = false;
          }
        }
    if (nof) cout << "No solution.\n";
    //cout << N << '\n';
  }
  return 0;
}

