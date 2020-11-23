// Copyright (C) 2016 by iamslash

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <limits>
#include <cstring>

int N = 5;

// 그래프의 인접 행렬
// adj[i][j] = i와 j사이의 간선의 수
std::vector<std::vector<int> > adj;

// 무향 그래프의 인접 행렬 adj가 주어질 때 오일러 서킷을 계산한다.
// 결과로 얻어지는 circuit을 뒤집으면 오일러 서킷이 된다.
void PrintVInt(const std::vector<int>& v) {
  for (int i = 0; i < v.size(); ++i) {
    printf("%d ", v[i]);
  }
  printf("\n");
}

void GetEulerCircuit(int here, std::vector<int>& circuit) {
  for (int there = 0; there < adj.size(); ++there) {
    while(adj[here][there] > 0) {
      adj[here][there]--;
      adj[there][here]--;
      GetEulerCircuit(there, circuit);
    }
  }
  circuit.push_back(here);
}

int main() {
    adj = std::vector<std::vector<int> >(N, std::vector<int>(N, 0));
    adj[0][1] = 1;
    adj[0][2] = 1;
    adj[1][2] = 1;
    adj[2][3] = 1;
    adj[2][0] = 1;
    adj[3][4] = 1;
    adj[4][0] = 1;

    std::vector<int> c;
    GetEulerCircuit(0, c);
    PrintVInt(c);
  //
  return 0;
}
