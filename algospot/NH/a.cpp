// Copyright (C) 2016 by iamslash
// https://algospot.com/judge/problem/read/NH

#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <queue>

int N, M;
const int MOD = 10007;
const int ALPHABETS = 26;

int CACHE[101][1001];

struct TrieNode {
  TrieNode* children[ALPHABETS];
  int terminal;  // index of M
  TrieNode* fail;
  std::vector<int> output;
  int no;
  TrieNode* next[ALPHABETS];

  TrieNode() : terminal(-1), fail(NULL) {
    for (int i = 0; i < ALPHABETS; ++i) {
      children[i] = NULL;
      next[i] = NULL;
    }
  }
  ~TrieNode() {
    for (int i = 0; i < ALPHABETS; ++i) {
      if (children[i] != NULL)
        delete children[i];
    }
  }
  int tonum(char c) {
    return c - 'A';
  }
  void insert(const char* key, int idx) {
    // base condition
    if (*key == 0) {
      terminal = idx;
      return;
    }
    // recursion
    int next = tonum(*key);
    if (children[next] == NULL)
      children[next] = new TrieNode();
    children[next]->insert(key + 1, idx);
  }
};

// BFS
void compute_fail_output(TrieNode* root) {
  std::queue<TrieNode*> q;
  root->fail = root;
  q.push(root);
  while (!q.empty()) {
    TrieNode* here = q.front();
    q.pop();
    for (int edge = 0; edge < ALPHABETS; ++edge) {
      TrieNode* child = here->children[edge];
      if (child == NULL)
        continue;
      if (here == root) {
        child->fail = root;
      } else {
        // CAUTION
        TrieNode* t = here->fail;
        while (t != root && t->children[edge] == NULL)
          t = t->fail;
        // t is root or nonroot
        if (t->children[edge] != NULL)
          t = t->children[edge];
        child->fail = t;
      }
      // set output
      child->output = child->fail->output;
      if (child->terminal != -1)
        child->output.push_back(child->terminal);
      q.push(child);
    }
  }
}

void compute_next(TrieNode* here, int& node_idx) {
  here->no = node_idx++;
  for (int c = 0; c < ALPHABETS; ++c) {
    TrieNode* next = here;
    while (next != next->fail && next->children[c] == NULL)
      next = next->fail;
    if (next->children[c] != NULL)
      next = next->children[c];
    here->next[c] = next;
    if (here->children[c] != NULL)
      compute_next(here->children[c], node_idx);
  }
}

// dp
int count(int length, TrieNode* state) {
  // base condition
  if (state->output.size() > 0)
    return 0;
  if (length == 0)
    return 1;
  // memoization
  int& r = CACHE[length][state->no];
  if (r != -1)
      return r;
  // recursion
  for (int c = 0; c < ALPHABETS; ++c) {
    r += count(length - 1, state->next[c]);
    r %= MOD;
  }

  return r;
}

int main() {
  int T;
  scanf("%d", &T);

  for (int t = 0; t < T; ++t) {
    // printf("[%d] before init CACHE\n", t);

    // init variables;
    for (int i = 0; i < 101; ++i)
      for (int j = 0; j < 1001; ++j)
        CACHE[i][j] = -1;
    // memset(CACHE, -1, sizeof(int) * sizeof (CACHE));
    // printf(" %d\n", sizeof(CACHE));
    // printf("[%d] after init CACHE\n", t);

    scanf("%d", &N);
    scanf("%d", &M);

    TrieNode tn;
    TrieNode* ptn = &tn;

    for (int i = 0; i < M; ++i) {
      char buf[128];
      scanf("%s", buf);
      ptn->insert(buf, i);
    }

    compute_fail_output(ptn);
    int nc = 0;
    compute_next(ptn, nc);

    printf("%d\n", count(N, ptn));
  }
  //
  return 0;
}
