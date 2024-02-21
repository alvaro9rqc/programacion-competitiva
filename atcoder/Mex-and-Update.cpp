#include <bits/stdc++.h>

using namespace std;
struct Node {
  int frecuency;
  bool exist;
};

class SegmentTree {
  public:
    int n;
    vector<Node> nodes;
    vector<int> A;

    SegmentTree(int nuevo) {
      n = nuevo;
      nodes.assign(4 * n, Node{0, false});
    }

    void update(int idx, int left, int right, int pos, int val) {
      if (left == right) {
        if (nodes[idx].frecuency >= 0)
          nodes[idx].frecuency += val;
        nodes[idx].exist = nodes[idx].frecuency > 0;
        return;
      }
      int mid = (left + right) / 2;
      if (left <= pos && pos <= mid) 
        update(2 * idx + 1, left, mid, pos, val);
      else 
        update(2 * idx + 2, mid + 1, right, pos, val);
      nodes[idx].exist = nodes[2 * idx + 1].exist & nodes[2 * idx + 2].exist;
    }

    int mex() {
      if (nodes[0].exist) 
        return n;
      else 
        return (mex(0, 0, n-1));
    }

    int mex(int idx, int left, int right) {
      int mid = (left + right) / 2;
      //cout << "=>" << left << "-" << right << '\n';
      if (left == right ) {
        return left;
      }
      else {
        int leftChild = 2 * idx + 1;
        int rightChild = 2 * idx + 2;
        if (nodes[leftChild].exist) 
          return mex(rightChild, mid + 1, right);
        else 
          return mex(leftChild, left, mid);
      }
    }
};
int main () {
  int n, q, a, i, x; scanf("%d %d", &n, &q);
  vector<int> A; //se crea la lista para acceder a los elementos 
  SegmentTree solver(n);
  int j = n;
  while (j --) {
    scanf("%d", &a);
    //cout << a << " ";
    solver.update(0, 0, n - 1, a, +1); //Se actualizan los elementos dentro del Seg. Tree
    A.push_back(a); //se añaden los elementos a la lista
  }
  while (q--) { //Por todas las queries
    scanf("%d %d", &i, &x);
    solver.update(0, 0, n - 1, A[i - 1], -1); //se resta la frecuencia de 
    solver.update(0, 0, n - 1, x, +1);
    A[i - 1] = x;
    cout << solver.mex() << "\n";
  }
  return 0;

  //SegmentTree solver(8);
  //solver.update(0, 0, 8 - 1, 0, +1);
  //solver.update(0, 0, 8 - 1, 1, +1);
  //solver.update(0, 0, 8 - 1, 2, +1);
  //solver.update(0, 0, 8 - 1, 2, -1);
  //solver.update(0, 0, 8 - 1, 2, -1);
  //solver.update(0, 0, 8 - 1, 2, +1);
  //cout << solver.mex() << '\n';
}
