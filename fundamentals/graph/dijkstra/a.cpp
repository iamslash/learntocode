// Copyright (C) 2016 by iamslash

#include <cstdio>
#include <vector>
#include <map>
#include <queue>

#define MAX_V 7
#define MAX_INT 987654321

int V = MAX_V;
std::vector<std::pair<int, int> > adj[MAX_V];

void print_v_int(const std::vector<int>& v) {
  for (int i = 0; i < v.size(); ++i) {
    printf("[%c]%d ", 'a'+i, v[i]);
  }
  printf("\n");
}

std::vector<int> dijkstra(int src) {
  std::vector<int> dist(V, MAX_INT);
  dist[src] = 0;
  std::priority_queue<std::pair<int, int> > pq;
  pq.push(std::make_pair(0, src));
  while (!pq.empty()) {
    int cost = -pq.top().first;
    int here = pq.top().second;
    pq.pop();
    //
    if (dist[here] < cost)
      continue;
    //
    for (int i = 0; i < adj[here].size(); ++i) {
      int there = adj[here][i].first;
      int there_cost = cost + adj[here][i].second;
      if (dist[there] > there_cost) {
        dist[there] = there_cost;
        pq.push(std::make_pair(-there_cost, there));
      }
    }
  }
  return dist;
}

int main() {
  for (int i = 0; i < MAX_V; ++i)
    adj[i].clear();

  adj[0].push_back(std::make_pair(1, 5));
  adj[0].push_back(std::make_pair(2, 1));

  adj[1].push_back(std::make_pair(0, 5));
  adj[1].push_back(std::make_pair(3, 1));
  adj[1].push_back(std::make_pair(5, 3));
  adj[1].push_back(std::make_pair(6, 3));

  adj[2].push_back(std::make_pair(0, 1));
  adj[2].push_back(std::make_pair(3, 2));

  adj[3].push_back(std::make_pair(1, 1));
  adj[3].push_back(std::make_pair(2, 2));
  adj[3].push_back(std::make_pair(4, 5));
  adj[3].push_back(std::make_pair(6, 3));

  adj[4].push_back(std::make_pair(3, 5));

  adj[5].push_back(std::make_pair(1, 3));
  adj[5].push_back(std::make_pair(6, 2));

  adj[6].push_back(std::make_pair(1, 3));
  adj[6].push_back(std::make_pair(3, 3));
  adj[6].push_back(std::make_pair(5, 2));

  std::vector<int> r = dijkstra(0);

  print_v_int(r);

  return 0;
}
