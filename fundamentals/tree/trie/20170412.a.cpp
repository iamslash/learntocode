// Copyright (C) 2016 by iamslash

#include <vector>

const int ALPHABETS = 26;
int to_num(char c) {
  return c - 'A';
}

struct TrieNode {
  TrieNode* children[ALPHABETS];
  bool terminal;
  TrieNode() : terminal(false) {
    for (int i = 0; i < ALPHABETS; ++i)
      children[i] = NULL;
  }
  ~TrieNode() {
    for (int i = 0; i < ALPHABETS; ++i)
      if (children[i] != NULL)
        delete children[i];
  }
  void insert(const char* key) {
    // base condition
    if (*key == 0) {
      terminal = true;
      return;
    }
    // recursion
    int next = to_num(*key);
    if (children[next] == NULL)
      children[next] = new TrieNode();
    children[next]->insert(key + 1);
  }
  TrieNode* find(const char* key) {
    // base condition
    if (*key == 0)
      return this;
    int next = to_num(*key);
    if (children[next] == NULL)
      return NULL;
    // recursion
    return children[next]->find(key + 1);
  }
};

int main() {
  // a terminal character of literal string is 0.
  // const char * a = "hello";
  // printf("%d\n", *(a+5));

  TrieNode* ptn = new TrieNode();
  ptn->insert("hello");
  ptn->insert("world");
  TrieNode* ptn0 = ptn->find("hello");
  TrieNode* ptn1 = ptn->find("ello");
  if (ptn0)
    printf("hello is in\n");
  if (ptn1)
    printf("ello is in\n");
  delete ptn;
}
