#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int frecuency;
    bool exist;
};

class SegmentTree
{
public:
    int n;
    vector<Node> nodes;
    vector<int> A;

    SegmentTree(int _n)
    {
        n = _n;
        // nodes.resize(4 * n);
        nodes.assign(4 * n, Node{0, false});
    }

    // `index` es el indice en el segment tree que cubre el segmento
    // desde [left, ..., right]
    // `pos` es la posicion que queremos actualizar
    // `val` es el valor a actualizar para el elemento en la posicion `pos`
    void update(int index, int left, int right, int pos, int val)
    {
        if (left == right)
        {
            nodes[index].frecuency += val;
            nodes[index].exist = nodes[index].frecuency > 0;
            return;
        }

        int mid = (left + right) / 2;
        if (left <= pos && pos <= mid)
        {
            // first part definido por [left, ..., mid]
            update(2 * index + 1, left, mid, pos, val);
        }
        else
        {
            // second part definido por [mid+1, ..., right]
            update(2 * index + 2, mid + 1, right, pos, val);
        }
        nodes[index].exist = nodes[2 * index + 1].exist & nodes[2 * index + 2].exist;
    }

    int mex() {
        // caso especial
        if(nodes[0].exist) {
            return n;
        } else {
            return mex(0, 0, n-1);
        }
    }

    int mex(int index, int left, int right)
    {   
        int mid = (left + right) / 2;
        if (left == right)
        {
            return left;
        }
        else
        {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            if (nodes[leftChild].exist == false)
            {
                return mex(leftChild, left, mid);
            }
            else
            {
                return mex(rightChild, mid + 1, right);
            }
        }
    }
};

int main(int, char **)
{
    int n = 4;
    SegmentTree solver(n);
    solver.update(0, 0, n - 1, 0, +1);
    solver.update(0, 0, n - 1, 1, +1);
    solver.update(0, 0, n-1, 2, +1);
    // solver.update(0, 0, n - 1, 3, +1);

    cout << solver.mex() << endl;

    return 0;
}