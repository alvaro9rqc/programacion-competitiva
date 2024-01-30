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
      cout << "=>" << left << "-" << right << '\n';
      if (left == right ) {
        return left;
      }
      else {
        int leftChild = 2 * idx + 1;
        int rightChild = 2 * idx + 2;
        if (nodes[leftChild].exist) 
        {
          return mex(rightChild, mid + 1, right);
        }
        else 
          return mex(leftChild, left, mid);
      }
    }
};
int main () {
  int n, q, a, i, x; scanf("%d %d", &n, &q);
  vector <int> l;
  char dummy;
  SegmentTree s(n);
  while (scanf("%d%c", &a, &dummy)) {
    l.push_back(a);
    cout << ": " << a << '\n';
    if (dummy == '\n') break;
  }
  while (q--) {
    scanf("%d %d", &i, &x);
    s.update(0, 0, n - 1, i, +1);
    cout << s.mex() << '\n';
  }
  return 0;
}
