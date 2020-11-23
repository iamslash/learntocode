// Copyright (C) 2016 by iamslash
// https://algospot.com/judge/problem/read/INSERTION

#include <cstdio>
#include <cstdlib>
#include <map>

int N;
int shifted[50000];
int A[50000];

/////////////////////////////////////////////////////////////////////////////
// treap
typedef int KeyType;

struct Node {
  KeyType key;
  int priority, size;
  Node *left, *right;
  explicit Node(const KeyType& _key) : key(_key), priority(std::rand()),
                              size(1), left(NULL), right(NULL) {
  }
  void SetLeft(Node* _left) {
    left = _left;
    CalcSize();
  }
  void SetRight(Node* _right) {
    right = _right;
    CalcSize();
  }
  void CalcSize() {
    size = 1;
    if (left)
      size += left->size;
    if (right)
      size += right->size;
  }
};

typedef std::pair<Node*, Node*> NodePair;

NodePair Split(Node* root, KeyType key) {
  if (root == NULL)
    return NodePair(NULL, NULL);
  if (root->key < key) {
    NodePair rs = Split(root->right, key);
    root->SetRight(rs.first);
    return NodePair(root, rs.second);
  }
  NodePair ls = Split(root->left, key);
  root->SetLeft(ls.second);
  return NodePair(ls.first, root);
}

Node* Insert(Node* root, Node* node) {
  if (root == NULL)
    return node;
  if (root->priority < node->priority) {
    NodePair splitted = Split(root, node->key);
    node->SetLeft(splitted.first);
    node->SetRight(splitted.second);
    return node;
  } else if (node->key < root->key) {
    root->SetLeft(Insert(root->left, node));
  } else {
    root->SetRight(Insert(root->right, node));
  }
  return root;
}

Node* Merge(Node* a, Node* b) {
  if (a == NULL)
    return b;
  if (b == NULL)
    return a;
  if (a->priority < b->priority) {
    b->SetLeft(Merge(a, b->left));
    return b;
  }
  a->SetRight(Merge(a->right, b));
  return a;
}

Node* Erase(Node* root, KeyType key) {
  if (root == NULL)
    return root;
  if (root->key == key) {
    Node* r = Merge(root->left, root->right);
    delete root;
    return r;
  }
  if (key < root->key)
    root->SetLeft(Erase(root->left, key));
  else
    root->SetRight(Erase(root->right, key));
  return root;
}

Node* Kth(Node* root, int k) {
  int left_size = 0;
  if (root->left != NULL)
    left_size = root->left->size;
  if (k <= left_size)
    return Kth(root->left, k);
  if (k == left_size + 1)
    return root;
  return Kth(root->right, k - left_size -1);
}

int CountLessThan(Node* root, KeyType key) {
  if (root == NULL)
    return 0;
  if (root->key >= key)
    return CountLessThan(root->left, key);
  int ls = (root->left ? root->left->size : 0);
  return ls + 1 + CountLessThan(root->right, key);
}

/////////////////////////////////////////////////////////////////////////////

void Solve() {
  Node* root = NULL;

  // 트립을 생성한다.
  for (int i = 0; i < N; ++i) {
    root = Insert(root, new Node(i + 1));
  }
  // A채우기
  for (int i = N - 1; i>= 0; --i) {
    int larger = shifted[i];
    Node* k = Kth(root, i + 1 - larger);
    // printf("after Kth %d\n", i);
    A[i] = k->key;
    root = Erase(root, k->key);
  }
}

void PrintA() {
  for (int i = 0; i < N; ++i) {
    printf("%d ", A[i]);
  }
  printf("\n");
}

int main() {
  int T;
  scanf("%d", &T);

  for (int t = 0; t < T; ++t) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
      scanf("%d", &shifted[i]);
    }
    Solve();
    PrintA();

    // printf(" %d", t);
  }
  //
  return 0;
}
