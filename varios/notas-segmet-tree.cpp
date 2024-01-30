#include <bits/stdc++.h>
using namespace std;

struct Node {
  int frecuency;
  bool exist; //existe elemento o no en un segmente
};

class SegmentTree {
  public:
    int n; //n° de nodos
    vector<Node> nodes;
    vector <int> A;
    SegmentTree(int _n) {
      n = _n;
      nodes.resize(4*n); // En el peor de los casos 4
    }
    // index: indice en segment tree
    // cubre desde left to right
    // pos: posición que queremos actualizar
    // val: nuevo valor para actualizar
    void update(int index, int left, int right, int pos int val) {
      int mid = (left + right ) / 2;
      if (left == right) {
        nodes[index].frecuency += val;
      }
      // firts part: definido por left - mid
      update(2*index+1, left, mid, pos, val);
      // second part definido por mid + 1 - rigth
      update(2*index+2, mid+1, right, pod, val);
    }
}
int main (int, char**) {

  return 0;
}
