// Copyright (C) 2016 by iamslash
// https://algospot.com/judge/problem/read/WORDCHAIN

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <limits>
#include <string>
#include <algorithm>


const int ALPHABETS = 26;
int N;

// 그래프의 인접 행렬
// adj[i][j] = i와 j사이의 간선의 수
std::vector<std::vector<int> > adj;

// graph[i][j] = i로 시작해서 j로 끝나는 단어의 목록
std::vector<std::string> graph[ALPHABETS][ALPHABETS];

// indegree[i] = i로 시작하는 단어의 수
// outdegree[i] = i로 끝나는 단어의 수
std::vector<int> indegree, outdegree;

// 무향 그래프의 인접 행렬 adj가 주어질 때 오일러 서킷을 계산한다.
// 결과로 얻어지는 circuit을 뒤집으면 오일러 서킷이 된다.
void PrintVInt(const std::vector<int>& v) {
  for (int i = 0; i < v.size(); ++i) {
    printf("%d ", v[i]);
  }
  printf("\n");
}

void MakeGraph(const std::vector<std::string>& words) {
  //
  for (int i = 0; i < ALPHABETS; ++i)
    for (int j = 0; j < ALPHABETS; ++j)
      graph[i][j].clear();
  adj = std::vector<std::vector<int> >(ALPHABETS,
                                       std::vector<int>(ALPHABETS, 0));
  indegree = outdegree = std::vector<int>(ALPHABETS, 0);
  // 각 단어를 그래프에 추가한다.
  for (int i = 0; i < words.size(); ++i) {
    int a = words[i][0] - 'a';
    int b = words[i][words[i].size() - 1] - 'a';
    graph[a][b].push_back(words[i]);
    adj[a][b]++;
    outdegree[a]++;
    indegree[b]++;
  }
}

// 유향 그래프의 인접 행렬 adj가 주어질 때 오일러 서킷 혹은 트레일을
// 계산한다.
void GetEulerCircuit(int here, std::vector<int>& circuit) {
  for (int there = 0; there < adj.size(); ++there) {
    while (adj[here][there] > 0) {
      adj[here][there]--;
      GetEulerCircuit(there, circuit);
    }
  }
  circuit.push_back(here);
}

// 현재 그래프의 오일러 트레일이나 서킷을 반환한다.
std::vector<int> GetEulerTrailOrCircuit() {
  std::vector<int> circuit;

  // 우선 트레일을 찾아본다. 시작점이 존재하는 경우
  for (int i = 0; i < ALPHABETS; ++i) {
    if (outdegree[i] == indegree[i] + 1) {
      GetEulerCircuit(i, circuit);
      return circuit;
    }
  }
  // 아니면 서킷이니, 간선에 인접한 아무 정점에서나 시작한다.
  for (int i = 0; i < ALPHABETS; ++i) {
    if (outdegree[i]) {
      GetEulerCircuit(i, circuit);
      return circuit;
    }
  }
  // 모두 실패한 경우
  return circuit;
}

std::string solve(const std::vector<std::string>& words) {
  MakeGraph(words);

  // 오일러 서킷이나 트레일을 찾아낸다.
  std::vector<int> circuit = GetEulerTrailOrCircuit();

  // 모든 간선을 방문하지 못했으면 실패!
  if (circuit.size() != words.size() + 1)
    return "IMPOSSIBLE";

  // 아닌 경우 방문 순서를 뒤집은 뒤 간선들을 모아 문자열로 만들어 반환한다.
  std::reverse(circuit.begin(), circuit.end());
  std::string r;

  for (int i = 1; i < circuit.size(); ++i) {
    int a = circuit[i - 1];
    int b = circuit[i];
    if (r.size() > 1)
      r += " ";
    r += graph[a][b].back();
    graph[a][b].pop_back();
  }

  return r;
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

    printf("%s\n", solve(words).c_str());
  }
  //
  return 0;
}
