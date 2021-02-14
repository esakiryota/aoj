#include<iostream>
using namespace std;
#define MAX 100005
#define NIL -1

struct Node { int p, l, r; };

Node T[MAX];
int D[MAX];

void rec(int u, int p) {
  D[u] = p;
  if (T[u].r != NIL) rec(T[u].r, p);
  if (T[u].l != NIL) rec(T[u].l, p + 1);
}

void treePrint(int node) {
  cout << "node" << " " << node << ": ";
  if (T[node].p == NIL) cout << "parent = " << NIL << ", ";
  else cout << "parent = " << T[node].p << ", ";
  cout << "depth = " << D[node] << ", ";
  if (T[node].p == NIL) cout << "root" << ", ";
  else if (T[node].l != NIL) cout << "internal node" << ", ";
  else cout << "leaf" << ", ";

  cout << "[";
  if (T[node].l != NIL) {
    int t = T[node].l;
    while(1) {
      cout << t;
      if (T[t].r == NIL) {
        break;
      }
      cout << ", ";
      t = T[t].r;
    }
  }
  cout << "]" << endl;


}

int main () {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) T[i].p = T[i].l = T[i].r = NIL;

  int m, v, w, l;
  for (int i = 0; i < n; i++) {
    cin >> m >> v;
    for (int j = 0; j < v; j++) {
      cin >> w;
      if ( j == 0 ) T[m].l = w;
      else T[l].r = w;
      l = w;
      T[w].p = m;
    }
  }

  int r;

  for (int i = 0; i < n; i++) {
    if (T[i].p == NIL) r = i;
  }
  rec(r, 0);

  for (int i = 0; i < n; i++) {
    treePrint(i);
  }
}
