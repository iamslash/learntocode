// Copyright (C) 2016 by iamslash

#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <queue>

const int ALPHABETS = 26;
int ToNumber(char ch) {
  return ch - 'A';
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
  
  TrieNode() : terminal(-1), fail(NULL) {
    memset(children, 0, sizeof(children));
  }
  ~TrieNode() {
    for (int i = 0; i < ALPHABETS; ++i)
      if (children[i])
        delete children[i];
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

  // TrieNode* Find(const char* key) {
  //   if (*key == 0)
  //     return this;
  //   int next = ToNumber(*key);
  //   if (children[next] == NULL)
  //     return NULL;
  //   return children[next]->Find(key + 1);
  // }
};

// 트라이가 주어질 때 각 노드에 대해 실패 연결과 출력 문자열 목록을
// 계산한다.
void BuildFailLink(TrieNode* root) {
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

std::vector<std::pair<int, int> > AhoCorasicSearch(
    const std::string& s, TrieNode* root) {
  std::vector<std::pair<int, int> > r;
  TrieNode* state = root;

  // 실제 반복문 내는 KMP와 별로 다를 것이 없다.
  for (int i = 0; i < s.size(); ++i) {
    // printf(" %d\n", i);

    int chr = ToNumber(s[i]);
    while (state != root && state->children[chr] == NULL)
      state = state->fail;
    // printf("  %d\n", i);
    
    // explorer children
    if (state->children[chr])
      state = state->children[chr];

    // found it
    for (int j = 0; j < state->output.size(); ++j)
      r.push_back(std::make_pair(i, state->output[j]));
    // printf("   %d\n", i);
  }  
  return r;
}

int main() {
  // needles
  std::vector<std::string> v;
  v.push_back("HELLO");
  v.push_back("WORLD");

  // build trie  
  TrieNode* ptn = new TrieNode();
  for (int i = 0; i < v.size(); ++i) {
    ptn->Insert(v[i].c_str(), i);    
  }
  BuildFailLink(ptn);

  // search
  std::vector<std::pair<int, int> > r = AhoCorasicSearch(
      "THISISHELLOWORLD", ptn);

  // print result
  for (auto it = r.begin(); it != r.end(); ++it) {
    int idxterm = (*it).first;
    int order = (*it).second;
    printf("%d %d\n", order, idxterm - v[order].size() + 1);
  }

  delete ptn;
}
