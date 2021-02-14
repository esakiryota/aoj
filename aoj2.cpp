#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int insertionSort(vector<int> A, int N) {
  int i,j,v;
  for(int i = 1; i < N; i++) {
    v = A.at(i);
    j = i-1;
    while (j >= 0 && A.at(j) > v) {
      A.at(j+1) = A.at(j);
      j--;
    }
    A.at(j+1) = v;
    for (int m = 0; m < N; m++){
      cout << A.at(m);
      if (m < N-1) {
        cout << " ";
      }
    }
    cout << endl;
  }
}

int main() {
  int N;
  cin >> N;
  vector<int> vec(100);
  for (int i = 0; i < N; i++) cin >> vec.at(i);
  for (int m = 0; m < N; m++){
    cout << vec.at(m);
    if (m < N-1) {
      cout << " ";
    }
  }
  cout << endl;
  insertionSort(vec, N);

  return 0;
}
