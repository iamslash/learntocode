// Copyright (C) 2016 by iamslash

#include <cstdio>

const int ALPHABETS = 26;

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
  int tonum(char c) {
    return c - 'A';
  }
  void insert(const char* key) {
    // base condition
    if (*key == 0) {
      terminal = true;
      return;
    }
    // recursion
    int next = tonum(*key);
    if (children[next] == NULL)
      children[next] = new TrieNode();
    children[next]->insert(key + 1);
  }
  TrieNode* find(const char* key) {
    // base condition
    if (*key == 0) {
      return this;
    }
    int next = tonum(*key);
    if (children[next] == NULL)
      return NULL;
    // recursion
    return children[next]->find(key + 1);
  }
};

int main() {
  TrieNode* ptn = new TrieNode();
  ptn->insert("there");
  ptn->insert("their");
  ptn->insert("the");
  ptn->insert("answer");
  ptn->insert("a");
  ptn->insert("bye");

  if (ptn->find("hello") != NULL)
    printf("hello is in\n");
  if (ptn->find("their") != NULL)
    printf("their is in\n");
  if (ptn->find("the") != NULL)
    printf("the is in\n");

  delete ptn;
}
