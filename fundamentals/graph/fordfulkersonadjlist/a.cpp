// Copyright (C) 2016 by iamslash

#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <cstdlib>

const int MAX_V = 4;
const int MAX_I = 987654321;
int V = MAX_V;

struct Edge {
  int target, capacity, flow;
  Edge* reverse;
  int ResidualCapacity() const {
    return capacity - flow;
  }
  void push(int amt) {
    flow += amt;
    reverse->flow -= amt;
  }
};

std::vector<Edge*> adj[MAX_V];

void AddEdge(int u, int v, int capacity) {
  Edge* uv = new Edge();
  Edge* vu = new Edge();

  uv->target = v;
  uv->capacity = capacity;
  uv->flow = 0;
  uv->reverse = vu;

  vu->target = u;
  vu->capacity = 0;
  vu->flow = 0;
  vu->reverse = uv;

  adj[u].push_back(uv);
  adj[v].push_back(vu);
}

Edge* GetEdge(int u, int v) {
  Edge* r = NULL;
  for (int i = 0; i < adj[u].size(); ++i) {
    r = adj[u][i];
    if (r->target == v) {
      break;
    }
  }
  return r;
}

int NetworkFlow(int src, int snk) {
  int r = 0;

  while (true) {
    std::vector<int> parent(MAX_V, -1);
    std::queue<int> q;
    parent[src] = src;
    q.push(src);

    while (!q.empty() && parent[snk] == -1) {
      int u = q.front();
      q.pop();
      for (int i = 0; i < adj[u].size(); ++i) {
        Edge* e = adj[u][i];
        int v = e->target;
        if (e->ResidualCapacity() > 0 &&
            parent[v] == -1) {
          q.push(v);
          parent[v] = u;
        }
      }
    }
    if (parent[snk] == -1)
      break;
    int amount = MAX_I;

    // TODO: 
    for (int v = snk; v != src; v = parent[v]) {
      int u = parent[v];
      amount = std::min(amount, GetEdge(u, v)->ResidualCapacity() );
    }
    for (int v = snk; v != src; v = parent[v]) {
      int u = parent[v];
      GetEdge(u, v)->push(amount);
    }
    r += amount;
  }
  return r;
}

int main() {
  AddEdge(0, 1, 1);
  AddEdge(0, 2, 2);
  AddEdge(1, 3, 3);
  AddEdge(1, 2, 1);
  AddEdge(2, 3, 1);
  
  printf("%d\n", NetworkFlow(0, 3));
}
