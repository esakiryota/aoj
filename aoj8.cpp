#include<iostream>
#include<algorithm>
#include<vector>
#include <typeinfo>
#include <cstdlib>
#include <cstdio>
using namespace std;

//nodeを勉強してから
//node

struct Node {
  int key;
  Node *next, *prev;
};

Node *nil;

Node* listSearch(int key) {
  Node *cur = nil->next;
  while ( cur != nil && cur->key != key)
}
