#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<vector>
using namespace std;
#define MAX 100000
#define VMAX 10000


int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  vector<int> C(VMAX);
  vector<int> B(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  for (int i = 0; i < VMAX; i++) C.at(i) = 0;
  for(int i = 0; i < N; i++) {
    C.at(A.at(i)) += 1;
  }
  for (int i = 1; i < VMAX; i++) C.at(i) = C.at(i) + C.at(i - 1);

  for (int i = 0; i < N; i++) {
    B.at(C.at(A.at(i))-1) = A.at(i);
    C.at(A.at(i)) -= 1;
  }

  for (int i = 0; i < N; i++) {
    if (i) cout << " ";
    cout << B.at(i);
  }

  cout << endl;

  return 0;
}
