#include<iostream>
#include<algorithm>
#include<vector>
#include <typeinfo>
#include <cstdlib>
#include <cstdio>
using namespace std;

int top, S[1000];

void push(int x) {
  S[++top] = x;
}

int pop() {
  top--;
  return S[top+1];
}

int main() {
  int a, b;
  top = 0;
  // char l[100];
  char l[1000];
  while(cin >> l) {
    if (l[0] == '+'){
      a = pop();
      b = pop();
      push(a + b);
    } else if (l[0] == '-') {
      a = pop();
      b = pop();
      push(b-a);
    } else if (l[0] == '*') {
      a = pop();
      b = pop();
      push(a * b);
    } else {
      push(atoi(l));
    }
    if ( getchar() == '\n') {
      break;
    };
  };
  cout << pop() << endl;
}
