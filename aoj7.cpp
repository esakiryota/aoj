#include<iostream>
#include<algorithm>
#include<vector>
#include <typeinfo>
#include <cstdlib>
#include <cstdio>
using namespace std;

struct Pair {
  string name;
  int t;
};

int LEN = 100;

int head, tail;
Pair Q[10000];
int elasp = 0;

void enqueue(Pair x) {
  Q[tail] = x;
  tail = tail + 1;
}

Pair dequeue() {
  Pair x = Q[head];
  head = head + 1;
  return x;
}

int min(int x, int y) {
  return x < y ? x : y;
}

int main() {
  int N, s;
  cin >> N >> s;
  string na;
  int ti;
  for (int i = 0; i < N; i++) cin >> Q[i].name >> Q[i].t;

  head = 0;
  tail = N;

  while (head != tail) {
    Pair u = dequeue();
    int c = min(s, u.t);
    u.t -= c;
    elasp += c;
    if (u.t > 0) enqueue(u);
    else cout << u.name << ' ' << elasp << endl;
  }

  return 0;
}
