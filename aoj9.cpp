#include<iostream>
#include<algorithm>
#include<vector>
#include <typeinfo>
#include <cstdlib>
#include <cstdio>
using namespace std;

int search(vector<int> A, int a, int &count) {
  for (int j = 0; j < A.size(); j++) {
    if (A.at(j) == a) {
      count++;
      break;
    }
  }
}

int main() {
  int n, m;
  cin >> n;
  vector<int> vec1(n);
  for (int i = 0; i < n; i++) cin >> vec1.at(i);
  cin >> m;
  vector<int> vec2(m);
  for (int i = 0; i < m; i++) cin >> vec2.at(i);

  int count = 0;

  for (int i = 0; i < vec2.size(); i++) {
    search(vec1, vec2.at(i), count);
  }

  cout << count << endl;
}
