// Copyright (C) 2016 by iamslash
// https://algospot.com/judge/problem/read/DICTIONARY

#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <queue>

int N;

// 알파벳의 각 글자에 대한 인접 행렬 표현 간선 (i, j)는 알파벳 i가
// j보다 앞에 와야 함을 나타낸다.
std::vector<std::vector<int> > adj;
std::vector<int> seen, order;

int ToNumber(const char& c) {
  return c - 'a';
}

// 주어진 단어들로부터 알파벳 간의 선후 관계 그래프를 생성한다.
void MakeGraph(const std::vector<std::string>& words) {
  adj = std::vector<std::vector<int> >(26, std::vector<int>(26, 0));
  for (int j = 1; j < words.size(); ++j) {
    int i = j - 1;
    int len = std::min(words[i].size(), words[j].size());
    // words[i]가 words[j]앞에 오는 이유를 찾는다.
    for (int k = 0; k < len; ++k) {
      if (words[i][k] != words[j][k]) {
        int a = ToNumber(words[i][k]);
        int b = ToNumber(words[j][k]);
        adj[a][b] = 1;
        break;
      }
    }
  }
}

void dfs(int here) {
  seen[here] = 1;
  for (int there = 0; there < adj.size(); ++there) {
    if (adj[here][there] == 1 && seen[there] != 1)
      dfs(there);
  }
  order.push_back(here);
}

// adj에 주어진 그래프를 위상 정렬한 결과를 반환한다.
// 그래프가 DAG가 아니라면 빈 벡터를 반환한다.
std::vector<int> TopologicalSort() {
  int n = adj.size();
  seen = std::vector<int>(n, 0);
  order.clear();
  for (int i = 0; i < n; ++i) {
    if (seen[i] != 1)
      dfs(i);
  }
  reverse(order.begin(), order.end());
  // 만약 그래프가 DAG가 아니라면 정렬 결과에 역방향 간선이 있다.
  for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j)
      if (adj[order[j]][order[i]])
        return std::vector<int>();
  // 없는 경우라면 깊이 우선 탐색에서 얻은 순서를 반환한다.
  return order;
}

void PrintVInt(const std::vector<int>& v) {
  if (v.size() == 0) {
    printf("INVALID HYPOTHESIS");
  } else {
    for (int i = 0; i < v.size(); ++i) {
      printf("%c", v[i]+'a');
    }
  }
  printf("\n");
}

int main() {
  int T;
  scanf("%d", &T);

  for (int t = 0; t < T; ++t) {
    std::vector<std::string> words;
    scanf("%d", &N);

    for (int i = 0; i < N; ++i) {
      char buf[128];
      scanf("%s", buf);
      words.push_back(buf);
    }

    MakeGraph(words);
    std::vector<int> r = TopologicalSort();

    PrintVInt(r);
  }
  //
  return 0;
}
