// Copyright (C) 2016 by iamslash
// https://algospot.com/judge/problem/read/SOLONG

#include <string>
#include <map>
#include <vector>
#include <limits>
#include <cstring>
#include <algorithm>

const int ALPHABETS = 26;
int ToNumber(char ch) {
  return ch - 'A';
}

int N, M;
// abc'\0'
struct TrieNode {
  TrieNode * children[ALPHABETS];
  int terminal;
  int first;
  TrieNode() : first(-1), terminal(-1) {
    memset(children, 0, sizeof(children));
  }
  ~TrieNode() {
    for (int i = 0; i < ALPHABETS; ++i) {
      if (children[i] != NULL)
        delete children[i];
    }
  }
  void insert(const char * key, int id) {
    if (first == -1)
      first = id;
    if (*key == 0) {  // base condition
      terminal = id;
    } else {  // recursion
      int next = ToNumber(*key);
      if (children[next] == NULL)
        children[next] = new TrieNode();
      children[next]->insert(key + 1, id);
    }
  }

  // a, a'\0'
  TrieNode* find(const char* key) {
    if (*key == 0)
      return this;
    int next = ToNumber(*key);
    if (children[next] == NULL)
      return NULL;
    return children[next]->find(key + 1);
  }

  // 이 노느까지 타이핑해 왔을때 번호 id인 key를 타이핑 하기 위해 최소
  // 몇번의 키를 더 눌러야 하나?
  int type(const char* key, int id) {
    if (*key == 0)
      return 0;
    if (first == id)
      return 1;
    int next = ToNumber(*key);
    return 1 + children[next]->type(key + 1, id);
  }
};

int CountKeys(TrieNode* trie, const char* word) {
  TrieNode* node = trie->find(word);
  if (node == NULL || node->terminal == -1)
    return strlen(word);
  return trie->type(word, node->terminal);
}

TrieNode* readInput(int words) {
  std::vector<std::pair<int, std::string> > input;
  for (int i = 0; i < words; ++i) {
    char buf[11];
    int freq;
    scanf("%s %d", buf, &freq);
    input.push_back(std::make_pair(-freq, buf));
  }

  std::sort(input.begin(), input.end());
  TrieNode* trie = new TrieNode();
  for (int i = 0; i < input.size(); ++i) {
    trie->insert(input[i].second.c_str(), i);
  }
  trie->first = -1;
  return trie;
}

int main() {
  int T;
  scanf("%d", &T);

  for (int t = 0; t < T; ++t) {
    scanf("%d", &N);
    scanf("%d", &M);
    TrieNode* p_tn = readInput(N);
    std::vector<std::string> v;
    for (int i = 0; i < M; ++i) {
      char buf[16];
      scanf("%s", buf);
      v.push_back(buf);
    }
    int r = 0;
    for (auto it = v.begin(); it != v.end(); ++it) {
      int j = CountKeys(p_tn, (*it).c_str());
      r += j;
      // printf("%d %ld %s\n", j, it - v.begin(), (*it).c_str());
    }
    printf("%d\n", r + M - 1);
    delete p_tn;
  }
  //
  return 0;
}
