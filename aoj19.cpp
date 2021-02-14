#include<iostream>
using namespace std;
#define MAX 100005
#define NIL -1

struct Node { int parent, left, right; };

Node T[MAX];
int H[MAX], D[MAX];

int setHeight(int u) {
  int h1 = 0;
  int h2 = 0;
  if (T[u].left != NIL) h1 = setHeight(T[u].left) + 1;
  if (T[u].right != NIL) h2 = setHeight(T[u].right) + 1;
  return H[u] = (h1 > h2 ? h1: h2);
}

void setDepth(int u, int p) {
  D[u] = p;
  if (T[u].right != NIL) setDepth(T[u].right, p + 1);
  if (T[u].left != NIL) setDepth(T[u].left, p + 1);
}

int getSibling(int u) {
  if (T[u].parent == NIL) return NIL;
  if (T[T[u].parent].left == u) return T[T[u].parent].right;
  if (T[T[u].parent].right == u) return T[T[u].parent].left;
  return NIL;
}

void treePrint(int node) {
  cout << "node" << " " << node << ": ";
  if (T[node].parent == NIL) cout << "parent = " << NIL << ", ";
  else cout << "parent = " << T[node].parent << ", ";
  cout << "sibling = " << getSibling(node) << ", ";
  if (T[node].left != NIL && T[node].right != NIL) cout << "degree = " << 2 << ", ";
  else if (T[node].left != NIL || T[node].right != NIL) cout << "degree = " << 1 << ", ";
  else cout << "degree = " << 0 << ", ";
  cout << "depth = " << D[node] << ", ";
  cout << "height = " << H[node] << ", ";
  if (T[node].parent == NIL) cout << "root" << endl;
  else if (T[node].left != NIL || T[node].right != NIL) cout << "internal node" << endl;
  else cout << "leaf" << endl;
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) T[i].parent = T[i].left = T[i].right = NIL;

  int a, b, c;

  for (int i = 0; i < n; i++) {
    cin >> a >> b >> c;
    T[a].left = b;
    T[a].right = c;
    if (b != NIL) T[b].parent = a;
    if (c != NIL) T[c].parent = a;
  }

  int r;

  for (int i = 0; i < n; i++) {
    if (T[i].parent == NIL) r = i;
  }

  setHeight(r);
  setDepth(r, 0);

  for (int i = 0; i < n; i++) treePrint(i);

  return 0;



}
