#include <vector>
#include <cstdio>

int N = 5;
std::vector<std::vector<int> > adj;
std::vector<int> discovered;
int counter;

void BuildGraph() {
  adj.clear();
  adj.resize(N);
  discovered.clear();
  discovered.resize(N, -1);

  adj[0].push_back(1);
  adj[1].push_back(2);
  adj[1].push_back(3);
  adj[2].push_back(3);      
}


void Dfs(int here) {
  printf("%d ", here);
  discovered[here] = counter++;
  // recursion
  for (int i = 0; i < adj[here].size(); ++i) {
    int there = adj[here][i];
    if (discovered[there] == -1)
      Dfs(there);
  }
}


int main() {
  BuildGraph();

  for (int i = 0; i < N; ++i) {
    if (discovered[i] == -1)
      Dfs(i);
  }
  
  return 0;
}
