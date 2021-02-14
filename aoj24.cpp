#include<iostream>
using namespace std;
#define MAX 100000

int parent(int i) { return i / 2; }
int left(int i) { return i * 2; }
int right(int i) { return i * 2 +1; }

int main() {
  int N, A[MAX+1];

  cin >> N;
  for (int i = 1; i < N+1; i++) cin >> A[i];

  for (int i = 1; i < N+1; i++) {
    cout << "node " << i << ": key = " << A[i] << ", ";
    if ( parent(i) >= 1) cout << "parent key = " << A[parent(i)] << ", ";
    if ( left(i) <= N) cout << "left key = " << A[left(i)] << ", ";
    if ( right(i) <= N) cout << "right key = " << A[right(i)] << ", ";
    cout << endl;
  }

  return 0;
}
