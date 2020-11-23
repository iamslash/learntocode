// Copyright (C) 2016 by iamslash

#include <vector>

const int ALPHABETS = 26;
int ToNumber(char ch) {
  return ch - 'A';
}

// node of trie
struct TrieNode {
  TrieNode* children[ALPHABETS];
  // this node is terminal
  bool terminal;
  TrieNode() : terminal(false) {
    memset(children, 0, sizeof(children));
  }
  ~TrieNode() {
    for (int i = 0; i < ALPHABETS; ++i)
      if (children[i])
        delete children[i];
  }
  // 이 노드를 루트로 하는 트라이에 문자열 key를 추가한다.
  void insert(const char* key) {
    if (*key == 0) {
      terminal = true;
    } else {
      int next = ToNumber(*key);
      if (children[next] == NULL)
        children[next] = new TrieNode();
      children[next]->insert(key + 1);
    }
  }

  TrieNode* find(const char* key) {
    if (*key == 0)
      return this;
    int next = ToNumber(*key);
    if (children[next] == NULL)
      return NULL;
    return children[next]->find(key + 1);
  }
};

int main() {
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
