// Copyright (C) 2016 by iamslash
// https://algospot.com/judge/problem/read/FAMILYTREE

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <limits>

const int MAXINT = 2147483648;
const int MAXN = 100000;
int N, Q;

std::vector<int> child[MAXN];
int no2serial[MAXN];
int serial2no[MAXN];
int loc_in_trip[MAXN];
int depth[MAXN];
int next_serial;

struct RMQT {
  int m_n;
  std::vector<int> m_range_min;
  explicit RMQT(const std::vector<int>& v) {
    m_n = v.size();
    m_range_min.resize(m_n * 4);
    init(v, 0, m_n-1, 1);
  }
  int init(const std::vector<int>& v, int left, int right, int node) {
    // base condition
    if (left == right)
      return m_range_min[node] = v[left];
    // recursion
    int mid = (left + right) / 2;
    int left_min = init(v, left, mid, node * 2);
    int right_min = init(v, mid + 1, right, node * 2 + 1);
    return m_range_min[node] = std::min(left_min, right_min);
  }
  int query(int left, int right, int node, int node_left, int node_right) {
    // base condition
    if (right < node_left || left > node_right)
      return MAXINT;
    if (left <= node_left && node_right <= right)
      return m_range_min[node];

    // recursion
    int node_mid = (node_left + node_right) / 2;
    return std::min(query(left, right, node*2, node_left, node_mid),
                    query(left, right, node*2+1, node_mid+1, node_right));
  }
  int query(int left, int right) {
    return query(left, right, 1, 0, m_n - 1);
  }
};


void Traverse(int here, int d, std::vector<int>* trip) {
  no2serial[here] = next_serial;
  serial2no[next_serial] = here;
  ++next_serial;
  depth[here] = d;

  loc_in_trip[here] = trip->size();
  trip->push_back(no2serial[here]);

  for (int i = 0; i < child[here].size(); ++i) {
    Traverse(child[here][i], d+1, trip);
    trip->push_back(no2serial[here]);
  }
}

RMQT* PrepareRMQ(int* next_serial) {
  *next_serial = 0;
  std::vector<int> trip;
  Traverse(0, 0, &trip);
  return new RMQT(trip);
}

int Distance(RMQT* rmqt, int u, int v) {
  int lu = loc_in_trip[u];
  int lv = loc_in_trip[v];
  if (lu > lv)
    std::swap(lu, lv);

  int lca = serial2no[rmqt->query(lu, lv)];
  return depth[u] + depth[v] - 2 * depth[lca];
}

void solve(RMQT* rmqt, int from, int to) {
  printf("%d\n", Distance(rmqt, from, to));
}

int main() {
  int T;
  scanf("%d", &T);

  for (int t = 0; t < T; ++t) {
    scanf("%d", &N);
    scanf("%d", &Q);
    for (int i = 0; i < N; ++i) {
      child[i].clear();
    }
    for (int i = 1; i < N; ++i) {
      int parent;
      scanf("%d", &parent);
      child[parent].push_back(i);
    }
    RMQT * rmqt = PrepareRMQ(&next_serial);
    for (int i = 0; i < Q; ++i) {
      int q0, q1;
      scanf("%d %d", &q0, &q1);
      solve(rmqt, q0, q1);
    }
  }
  //
  return 0;
}
