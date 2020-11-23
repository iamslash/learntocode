// Copyright (C) 2016 by iamslash
// https://algospot.com/judge/problem/read/MEETINGROOM

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <limits>
#include <string>
#include <algorithm>
#include <stack>
#include <map>

int N;

std::vector<std::pair<int, int> > meetings;
// 그래프의 인접 리스트 표현
std::vector<std::vector<int> > adj;
// 각 정점의 컴포넌트 번호, 컴포넌트 븐호는 0부터 시작하며 같은 강결합
// 컴포넌트에 속한 정점들의 컴포넌트 번호가 같다.
std::vector<int> scc_id;
// 각 정점의 발견순서
std::vector<int> discovered, finished;
// 정점의 번호를 담는 스택
std::stack<int> st;
//
int scc_counter, vertex_counter = 0;

void PrintVInt(const std::vector<int>& v) {
  for (int i = 0; i < v.size(); ++i) {
    printf("%d ", v[i]);
  }
  printf("\n");
}

// here를 루트로 하는 서브 트리에서 역방향 간선이나 교차 간선을 통해
// 갈 수 있는 정점 중 최소 발견 순서를 반환한다.
int Scc(int here) {
  int r = discovered[here] = vertex_counter++;
  // 스택에 here를 넣는다. here의 후손들은 모두 스택에서 here후에
  // 들어간다.
  st.push(here);
  for (int i = 0; i < adj[here].size(); ++i) {
    int there = adj[here][i];
    //
    if (discovered[there] == -1)
      r = std::min(r, Scc(there));
    // there가 무시해야 하는 교차 간선이 아니라면
    else if (scc_id[there] == -1)
      r = std::min(r, discovered[there]);
  }
  // here에서 부모로 올라가는 간선을 끊어야 할지 확인한다.
  if (r == discovered[here]) {
    // hdre를 루트로 하는 서브트리에 남아 있는 정점들을 전부 하나의
    // 컴포넌트로 묶는다.
    while (true) {
      int t = st.top();
      st.pop();
      scc_id[t] = scc_counter;
      if (t == here)
        break;
    }
    scc_counter++;
  }
  finished[here] = 1;
  return r;
}

// tarjan의 scc알고리즘
std::vector<int> TarjanScc() {
  // 배열들을 전부 초기화
  scc_id = discovered = std::vector<int>(adj.size(), -1);
  finished = std::vector<int>(adj.size(), 0);
  // 카운터 초기화
  scc_counter = vertex_counter = 0;
  // 모든 정점에 대해 Scc()호출
  for (int i = 0; i < adj.size(); ++i) {
    if (discovered[i] == -1)
      Scc(i);
  }
  return scc_id;
}


// 두 구간 a와 b가 서로 겹치지 않는지를 확인한다.
bool Disjoint(const std::pair<int, int>& a,
              const std::pair<int, int>& b) {
  return a.second <= b.first || b.second <= a.first;
}

// meetings[]가 각 팀이 하고 싶어하는 회의 시간의 목록일 때, 이를
// 2-SAT문제로 변환한 뒤 함의 그래프를 생성한다.  i번 팀은
// meetings[2*i] 혹은 meetings[2*i + 1]중 하나 시간에 회의실을 써야
// 한다.
void MakeGraph(const std::vector<std::pair<int, int> >& meetings) {
  int vars = meetings.size();
  // 그래프는 각 변수마다 두개의 정점을 갖는다.
  adj.clear();
  adj.resize(vars * 2);
  for (int i = 0; i < vars; i += 2) {
    // 각 팀은 i번 회의나 j번 회의 둘 중 하나는 해야 한다.
    // (i or j)절을 추가한다.
    int j = i + 1;
    adj[i * 2 + 1].push_back(j * 2); // ~i => j
    adj[j * 2 + 1].push_back(i * 2); // ~j => i
  }
  for (int i = 0; i < vars; ++i) {
    for (int j = 0; j < i; ++j) {
      // i번 회의와 j번 회의가 서로 겹칠 경우
      if (!Disjoint(meetings[i], meetings[j])) {
        // i번 회의가 열리지 않거나, j번 회의가 열리지 않아야 한다.
        // (~i or ~j)절을 추가한다.
        adj[i * 2].push_back(j * 2 + 1); // i => ~j
        adj[j * 2].push_back(i * 2 + 1); // j => ~i
      }
    }
  }
}

// adj에 함의 그래프의 인접 리스트 표현이 주어질 때, 2-SAT문제의 답을 반환한다.
std::vector<int> Solve2sat() {
  int n = adj.size() / 2; // 변수의 수

  // 함의 그래프의 정점들을 강결합 요소별로 묶는다.
  std::vector<int> label = TarjanScc();

  // 이 SAT문제를 푸는 것이 불가능한지 확인한다. 한 변수를 나타내는 두 정점이
  // 같은 강결합 요소에 속해 있을 경우 답이 없다.
  for (int i = 0; i < 2 * n; i += 2) {
    if (label[i] == label[i+1]) {
      return std::vector<int>();
    }
  }

  // SAT문제를 푸는 것이 가능하다. 답을 생성하자!
  std::vector<int> value(2 * n, -1);

  // Tarjan알고리즘에서 SCC번호는 위상 정렬의 역순으로 배정된다.
  // SCC번호의 역순으로 각 정점을 정렬하면 위상 정렬 순서가 된다.
  std::vector<std::pair<int, int> > order;
  for (int i = 0; i < 2 * n; ++i) {
    order.push_back(std::make_pair(-label[i], i));
  }
  std::sort(order.begin(), order.end());

  // 각 정점에 값을 배정한다.
  for (int i = 0; i < 2 * n; ++i) {
    int vertex = order[i].second;
    int variable = vertex / 2;
    int is_true = vertex % 2;
    if (value[variable] != -1)
      continue;
    // not A가 A보다 먼저 나왔으면 A는 참
    // A가 not A보다 먼저 나왔으면 A는 거짓
    value[variable] = !is_true;
  }

  return value;
}

int main() {
  int T;
  scanf("%d", &T);

  for (int t = 0; t < T; ++t) {
    scanf("%d", &N);

    for (int i = 0; i < N; ++i) {
      int w, x, y, z;
      scanf("%d %d %d %d", &w, &x, &y, &z);
      meetings.push_back(std::make_pair(w, x));
      meetings.push_back(std::make_pair(y, z));
    }

    MakeGraph(meetings);
    std::vector<int> r = Solve2sat();

    if (r.size() == 0) {
      printf("IMPOSSIBLE\n");
    } else {
      printf("POSSIBLE\n");
      for (int i = 0; i < r.size(); ++i) {
        if (r[i] == 1)
          printf("%d %d", meetings[i].first, meetings[i].second);
      }
      printf("\n");
    }
  }
  //
  return 0;
}
