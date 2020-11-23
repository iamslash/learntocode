// Copyright (C) 2016 by iamslash
// https://algospot.com/judge/problem/read/DICTIONARY

#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <queue>

const int ALPHABETS = 26;
int N;
std::vector<std::vector<int> > adj;
std::vector<bool> visited;
std::vector<int> order;

int tonum(char c) {
  return 'a' - c;
}

char tochr(int n) {
  return 'a' + n;
}

void build_graph(const std::vector<std::string>& words) {
  for (int i = 0; i < words.size() - 1; ++i) {
    int len = std::min(words[i].size(), words[i+1].size());
    for (int j = 0; j < len; ++j) {
      if (words[i][j] != words[i+1][j]) {
        int a = tonum(words[i][j]);
        int b = tonum(words[i+1][j]);
        adj[a][b] = 1;
        break;
      }
    }
  }
}

void dfs(int here) {
  visited[here] = true;
  for (int there = 0; there < ALPHABETS; ++there) {
    if (adj[here][there] == 1 && visited[there] == false) {
      dfs(there);
    }
  }
  order.push_back(here);
}

std::vector<int> dfs_topological_sort() {
  for (int i = 0; i < ALPHABETS; ++i) {
    if (visited[i] == false) {
      dfs(i);
    }
  }
  std::reverse(order.begin(), order.end());

  // validate topological sort
  for (int i = 0; i < order.size() - 1; ++i) {
    for (int j = i; j < order.size(); ++j) {
      if (adj[order[j]][order[i]] == 1)
        return std::vector<int>();
    }
  }

  return order;
}

int main() {
  int T;
  scanf("%d", &T);

  for (int t = 0; t < T; ++t) {
    std::vector<std::string> words;
    scanf("%d", &N);
    adj = std::vector<std::vector<int> >(
        ALPHABETS, std::vector<int>(ALPHABETS, 0));
    visited.resize(ALPHABETS, false);
    order.clear();
    for (int i = 0; i < N; ++i) {
      char buf[32];
      scanf("%s", buf);
      words.push_back(buf);
    }

    build_graph(words);
    std::vector<int> r = dfs_topological_sort();

    // print result
    if (r.size() == 0) {
      printf("INVALID HYPOTHESIS");
    } else {
      for (int i = 0; i < r.size(); ++i) {
        printf("%c", tochr(r[i]));
      }
    }
    printf("\n");
  }
  //
  return 0;
}
