#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int bubbleSort(vector<string> &A, int N) {
  int flag = 1;
  while (flag) {
    flag = 0;
    for (int j = N-1; j > 0; j--) {
      if (A.at(j).at(1) < A.at(j-1).at(1)) {
        swap(A.at(j), A.at(j-1));
        flag = 1;
      }
    }
  }
}

int selectionSort(vector<string> &vec, int N) {
  for (int i = 0; i < N; i++) {
    int min = 200000;
    int minplace = i;
    for (int j = i; j < N; j++) {
      if (min > vec.at(j).at(1)) {
        min = vec.at(j).at(1);
        minplace = j;
      }
    }
    if (minplace != i) {
      swap(vec.at(i), vec.at(minplace));
    }
  }
}

bool isStalable(vector<string> &A, vector<string> &B, int N) {
  for (int i = 0; i < N; i++) {
    if (A.at(i) != B.at(i)) {
      return false;
    }
  }
  return true;
}

void vectorPrint(vector<string> vec, int N){
  for (int m = 0; m < N; m++){
    cout << vec.at(m);
    if (m < N-1) {
      cout << " ";
    }
  }
  cout << endl;
}

int main() {
  int N;
  vector<string> vec1(N);
  vector<string> vec2(N);
  cin >> N;
  for (int i = 0; i < N; i++) cin >> vec1.at(i);
  for (int i = 0; i < N; i++) vec2.at(i) = vec1.at(i);
  bubbleSort(vec1, N);
  selectionSort(vec2, N);

  vectorPrint(vec1, N);
  cout << "Stable" << endl;
  vectorPrint(vec2, N);
  if (isStalable(vec1, vec2, N)) {
    cout << "Stable" << endl;
  } else {
    cout << "Not stable" << endl;
  }
}
