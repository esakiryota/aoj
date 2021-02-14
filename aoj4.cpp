#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int selectionSort(vector<int> &vec, int N, int &count) {
  for (int i = 0; i < N; i++) {
    int min = 200000;
    int minplace = i;
    for (int j = i; j < N; j++) {
      if (min > vec.at(j)) {
        min = vec.at(j);
        minplace = j;
      }
    }
    if (minplace != i) {
      swap(vec.at(i), vec.at(minplace));
      count++;
    }
  }
}

int main() {
  int N;
  vector<int> vec(N);
  int count;
  cin >> N;
  for (int i = 0; i < N; i++) cin >> vec.at(i);
  selectionSort(vec, N, count);
  for (int m = 0; m < N; m++){
    cout << vec.at(m);
    if (m < N-1) {
      cout << " ";
    }
  }
  cout << endl;
  cout << count << endl;
}
