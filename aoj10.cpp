#include<iostream>
#include<algorithm>
#include<vector>
#include <typeinfo>
#include <cstdlib>
#include <cstdio>
using namespace std;


int search (vector<int> vec, int key, int n, int &count){
  int left, right, mid;
  left = 0;
  right = n;
  while(left < right) {
    mid = (left + right) / 2;
    if (key > vec.at(mid)) left = mid+1;
    else if (key == vec.at(mid)) {
      count++;
      break;
    } else if (key < vec.at(mid)) {
      right = mid;
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
    search(vec1, vec2.at(i), n, count);
  }

  cout << count << endl;

}
