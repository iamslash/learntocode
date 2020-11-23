// Copyright (C) 2016 by iamslash

#include <vector>
#include <string>

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
  void Insert(const char* key) {
    if (*key == 0) {
      terminal = true;
    } else {
      int next = ToNumber(*key);
      if (children[next] == NULL)
        children[next] = new TrieNode();
      children[next]->Insert(key + 1);
    }
  }

  TrieNode* Find(const char* key) {
    if (*key == 0)
      return this;
    int next = ToNumber(*key);
    if (children[next] == NULL)
      return NULL;
    return children[next]->Find(key + 1);
  }
};

int main() {
  TrieNode* ptn = new TrieNode();
  std::string s = "BANANAS";
  for (int i = 0; i < s.size(); ++i) {
    // printf("%s\n", s.substr(i).c_str());
    ptn->Insert(s.substr(i).c_str());
  }

  TrieNode* ptn0  = ptn->Find("NAS");
  if (ptn0)
    printf("%s is in", "NAS");
  delete ptn;
}
