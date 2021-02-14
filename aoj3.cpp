#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int bubbleSort(vector<int> &A, int N, int &count) {
  int flag = 1;
  while (flag) {
    flag = 0;
    for (int j = N-1; j > 0; j--) {
      if (A.at(j) < A.at(j-1)) {
        int m = A.at(j);
        A.at(j) = A.at(j-1);
        A.at(j-1) = m;
        flag = 1;
        count++;
      }
    }
  }
}

int main() {
  int N;
  vector<int> vec(N);
  int count = 0;
  cin >> N;
  for (int i = 0; i < N; i++) cin >> vec.at(i);
  bubbleSort(vec, N, count);

  for (int m = 0; m < N; m++){
    cout << vec.at(m);
    if (m < N-1) {
      cout << " ";
    }
  }
  cout << endl;
  cout << count << endl;
  }
