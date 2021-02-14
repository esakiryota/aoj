#include<iostream>
#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
#define MAX 100005
#define NIL -1

struct Node { int parent, left, right; };
Node T[MAX];

void preParse(int u) {
  if (u == NIL) return;
  printf(" %d", u);
  preParse (T[u].left);
  preParse (T[u].right);
}

void inParse(int u) {
  if (u == NIL) return;
  inParse (T[u].left);
  printf(" %d", u);
  inParse (T[u].right);
}

void postParse(int u) {
  if (u == NIL) return;
  postParse (T[u].left);
  postParse (T[u].right);
  printf(" %d", u);
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
  printf("Preorder\n");
  preParse(r);
  printf("\n");
  printf("Inorder\n");
  inParse(r);
  printf("\n");
  printf("Postorder\n");
  postParse(r);
  printf("\n");

  return 0;
}
