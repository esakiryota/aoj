#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N;
vector<int> A(100);

int solve(int i, int m) {
  if (m == 0) return 1;
  if (i >= N) return 0;
  int res = solve(i + 1, m) || solve(i + 1, m - A.at(i));
  return res;
}

int main() {
  int M;
  cin >> N;
  for(int i = 0; i < N; i++) cin >> A.at(i);
  cin >> M;
  for (int j = 0; j < M; j++) {
    int m;
    cin >> m;
  if(solve(0, m)) cout << "yes" << endl;
    else cout << "no" << endl;
  }

  return 0;
}
