// Copyright (C) 2016 by iamslash
// https://algospot.com/judge/problem/read/SOLONG

#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

const int ALPHABETS = 26;

int N, M;
std::vector<std::pair<int, int>> DICT;
std::vector<std::string> DICTWORDS;
std::vector<std::string> WORDS;

void print_v_string(const std::vector<std::string>& v) {
  for (auto x : v)
    printf("%s ", x.c_str());
  printf("\n");
}

struct TrieNode {
  TrieNode* children[ALPHABETS];
  int terminal;  // dictword index for terminal node
  int first;  // first recommendation
  TrieNode() : terminal(-1), first(-1) {
    for (int i = 0; i < ALPHABETS; ++i) {
      children[i] = NULL;
    }
  }
  ~TrieNode() {
    for (int i = 0; i < ALPHABETS; ++i) {
      if (children[i] != NULL)
        delete children[i];
    }
  }
  int to_num(char c) {
    return c - 'A';
  }
  void insert(const char * key, int idx) {
    // base condition
    if (first == -1)
      first = idx;
    if (*key == 0) {
      terminal = idx;
      printf("  insert:   idx: %2d first: %2d terminal: %2d\n",
             idx, first, terminal);
      return;
    }
    printf("  insert: %c idx: %2d first: %2d terminal: %2d\n",
           *key, idx, first, terminal);

    // recursion
    int next = to_num(*key);
    if (children[next] == NULL)
      children[next] = new TrieNode();
    children[next]->insert(key + 1, idx);
  }
  TrieNode* find(const char * key) {
    // base condition
    if (*key == 0)
      return this;
    // recursion
    int next = to_num(*key);
    if (children[next] == NULL)
      return NULL;
    return children[next]->find(key + 1);
  }
  int type(const char * key, int idx) {
    printf("    %c idx: %d first: %d\n", *key, idx, first);
    // base condition
    if (*key == 0)
      return 0;
    if (first == idx)
      return 1;
    // recursion
    int next = to_num(*key);
    return 1 + children[next]->type(key + 1, idx);
  }
};

TrieNode* build_trie() {
  TrieNode* proot = new TrieNode();
  std::sort(DICT.begin(), DICT.end());
  for (int i = 0; i < DICT.size(); ++i) {
    proot->insert(DICTWORDS[DICT[i].second].c_str(), DICT[i].second);
  }
  proot->first = -1;
  return proot;
}

int count_keys(TrieNode* proot, const std::string& w) {
  TrieNode* pnode = proot->find(w.c_str());
  if (pnode == NULL || pnode->terminal == -1) {
    // printf("  %s\n", w.c_str());
    return w.size();
  }
  // printf("  %s %d\n", w.c_str(), pnode->terminal);
  int r = pnode->type(w.c_str(), pnode->terminal);
  return r;
}

int solve() {
  int r = 0;
  TrieNode * proot = build_trie();
  for (int i = 0; i < WORDS.size(); ++i) {
    int cnt = count_keys(proot, WORDS[i]);
    printf("  %s %d\n", WORDS[i].c_str(), cnt);
    r += cnt;
  }
  delete proot;
  return r + WORDS.size() - 1;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    scanf("%d %d", &N, &M);
    DICT.clear(); DICT.resize(N);
    DICTWORDS.clear(); DICTWORDS.resize(N);
    WORDS.clear(); WORDS.resize(M);
    for (int i = 0; i < N; ++i) {
      char buf[16];
      int priority;
      scanf("%s %d", buf, &priority);
      DICTWORDS[i] = buf;
      DICT[i] = std::make_pair(-priority, i);
      printf("%d %s\n", i, DICTWORDS[i].c_str());
    }
    for (int i = 0; i < M; ++i) {
      char buf[16];
      scanf("%s", buf);
      WORDS[i] = buf;
    }
    // print_v_string(DICTWORDS);
    printf("%d\n", solve());
  }
  return 0;
}
