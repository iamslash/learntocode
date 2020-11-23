// Copyright (C) 2016 by iamslash
// https://algospot.com/judge/problem/read/NH

#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <queue>

int N, M;

const int MOD = 10007;
int CACHE[101][1001];  // CACHE[i][j] i=len, j=

const int ALPHABETS = 26;
int ToNumber(char ch) {
  return ch - 'a';
}

// node of trie
struct TrieNode {
  TrieNode* children[ALPHABETS];
  // 현 위치에서 끝나는 문자열의 번호
  int terminal;
  // 실패 연결: 이 노드에서 매칭이 실패했을 때 이 곳으로 가서
  // 계속한다.  이 노드에 대응되는 문자열의 접미사이면서 트라이에
  // 포함된 최대 문자열
  TrieNode* fail;
  // 출력 문자열 목록: 이노드가 방문되었을 때 등장하는 바늘 문자열들의
  // 번호
  std::vector<int> output;

  //
  int no;
  TrieNode* next[ALPHABETS];

  TrieNode() : terminal(-1), fail(NULL) {
    memset(children, 0, sizeof(children));
    memset(next, 0, sizeof(next));
  }
  ~TrieNode() {
    for (int i = 0; i < ALPHABETS; ++i) {
      if (children[i])
        delete children[i];
      // if (next[i])
      //   delete next[i];
    }
  }

  // 이 노드를 루트로 하는 트라이에 문자열 key를 추가한다.
  void Insert(const char* key, int order) {    
    if (*key == 0) {  // base condition
      terminal = order;    
    } else {  // recursion
      int next = ToNumber(*key);
      if (children[next] == NULL)
        children[next] = new TrieNode();
      children[next]->Insert(key + 1, order);
    }
  }
};


// 트라이가 주어질 때 각 노드에 대해 실패 연결과 출력 문자열 목록을
// 계산한다.
void ComputeFailFunc(TrieNode* root) {
  // 루트에서부터 시작해 한 단계씩 아래로 내려가며 각 노드의 실패
  // 연결을 계산한다.
  // queue for BFS
  std::queue<TrieNode*> q;
  // 루트의 실패 연결은 자기 자신
  root->fail = root;
  q.push(root);
  // BFS
  while (!q.empty()) {
    TrieNode* here = q.front();
    q.pop();
    // here의 모든 자손에 대해 실패 연결을 계산하고 이들을 큐에
    // 넣는다.
    for (int edge = 0; edge < ALPHABETS; ++edge) {
      TrieNode* child = here->children[edge];
      if (!child) continue;
      // 1레벨 노드의 실패 연결은 항상 루트
      if (here == root)
        child->fail = root;
      else {
        // 아닌 경우 부모의 실패 연결을 따라가면서 실패 연결을 찾는다.
        TrieNode* t = here->fail;
        while (t != root && t->children[edge] == NULL)
          t = t->fail;
        if (t->children[edge])
          t = t->children[edge];
        child->fail = t;
      }
      // 출력 문자열 목록: 실패 연결을 따라간 노드에서 복사해온 뒤
      // 이 위치에서 끝나는 바늘 문자열이 있으면 추가한다.
      child->output = child->fail->output;
      if (child->terminal != -1)
        child->output.push_back(child->terminal);
      q.push(child);
    }
  }
}


// 앞으로 length글자를 더 만들어야 하는데, 아호-코라식 알고리즘의 현재
// 상태가 state에 주어질 때 IDS에 걸리지 않는 문자열의 수는?
int Count(int length, TrieNode* state) {
  // base condition : 문자열이 검색되었다면 결과는 0이다.
  if (state->output.size())
    return 0;
  // base condition : 문자열을 전부 만든 경우
  if (length == 0)
    return 1;

  // memoization
  int& r = CACHE[length][state->no];
  if (r != -1)
      return r;

  // recursion
  for (int letter = 0; letter < ALPHABETS; ++letter) {
    r += Count(length - 1, state->next[letter]);
    r %= MOD;
  }

  return r;
}

// 상태 간의 전이 테이블을 next[]에 채운다. coputFailFunc()를 통해
// 이미 실패 함수가 계산되어 있다고 가정한다.
void ComputeTransition(TrieNode* here, int& node_counter) {
  // 0에서 시작하는 번호를 매긴다. CACHE[]의 인덱스
  here->no = node_counter++;

  // here뒤에 글자 char를 붙였을때 어느상태로 가는가?
  for (int chr = 0; chr < ALPHABETS; ++chr) {
    // next[]를 계산해서 저장한다.
    TrieNode* next = here;
    while (next != next->fail && next->children[chr] == NULL)
      next = next->fail;
    if (next->children[chr])
      next = next->children[chr];
    here->next[chr] = next;
    // 재귀적으로 모든 노드에 대해 전이 테이블을 계산한다.|
    if (here->children[chr])
      ComputeTransition(here->children[chr], node_counter);
  }
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
      ptn->Insert(buf, i);
    }

    ComputeFailFunc(ptn);
    int nc = 0;
    ComputeTransition(ptn, nc);

    printf("%d\n", Count(N, ptn));
  }
  //
  return 0;
}
