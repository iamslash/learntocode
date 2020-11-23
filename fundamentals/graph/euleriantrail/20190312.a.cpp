// Copyright (C) 2016 by iamslash

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <limits>
#include <cstring>
#include <algorithm>

int N = 5;

std::vector<std::vector<int> > adj;
std::vector<int> trail;

void print_v_int(const std::vector<int>& v) {
  for (int i = 0; i < v.size(); ++i) {
    printf("%d ", v[i]);
  }
  printf("\n");
}

void get_euler_circuit(int here) {
  for (int there = 0; there < N; ++there) {
    while (adj[here][there] > 0) {
      adj[here][there]--;
      adj[there][here]--;
      get_euler_circuit(there);
    }
  }
  trail.push_back(here);
}

void get_euler_trail(int start, int end) {
  adj[start][end] = 1;
  adj[end][start] = 1;
  get_euler_circuit(start);
  std::reverse(trail.begin(), trail.end());
  trail.pop_back();
}

int main() {
    adj = std::vector<std::vector<int> >(N, std::vector<int>(N, 0));
    adj[0][1] = 1;
    adj[1][0] = 1;
    adj[1][2] = 1;
    adj[2][1] = 1;

    get_euler_trail(0, 2);
    print_v_int(trail);
  //
  return 0;
}
