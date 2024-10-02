#include <bits/stdc++.h> 
using namespace std;
int main () {
  //I thought in a solution, 
  //first I make a priority queue (pq) of all the k rows, 
  //this way I get the fewest integer
  //I add the integers and get the first min sum
  //Later I make a pq of the fewest difference between
    // I rest the first with the second element of the firsts pq
    // And make a pq with this difference
  // Later I choose the min difference and add it with the sum
  // Finale I pop this difference and add the new. 
  // I do it k-1 times.
  int k;
  while (scanf("%d", &k) != EOF) {
    int n = k;
    int mtx[k][k];
    long sum1 = 0;
    priority_queue<tuple<int, int, int>> pq;
    for (int i = 0; i < k; i++) {
      for (int j = 0; j < k; j++) {
        scanf("%d", &mtx[i][j]);
      } 
      sort(mtx[i], mtx[i] + k);
      sum1 += mtx[i][0];
    }
    printf("%ld ", sum1); n--;
    for (int i = 0; i < k; i++) {
      int rest = mtx[i][1] - mtx[i][0];
      pq.push({-1 * rest, i, 1});
    }
    printf("%ld ", sum1 - get<0>(pq.top())); n--;
    while (n--) {
      int i = get<1>(pq.top());
      int j = get<2>(pq.top());
      int nrest = mtx[i][j + 1] - mtx[i][0];
      pq.pop();
      pq.push({-1 * nrest, i, j + 1});
      //printf("%ld ", sum1 - get<0>(pq.top()));
      cout << get<0>(pq.top()) << " ";
    }
    printf("\n");
    //cout << "end\n";

  }
  return 0;
}

