// Copyright (C) 2016 by iamslash
// https://algospot.com/judge/problem/read/FORTRESS

#include <cstdio>
#include <cmath>
#include <vector>

int N;
std::vector<int> vx;
std::vector<int> vy;
std::vector<int> vr;

int longest;

class Node {
 public:
  int idx;
  std::vector<Node*> children;
  explicit Node(int _idx) : idx(_idx) {}
};

// idx1 is included in idx0???
bool is_in(int idx0, int idx1) {
  int x0 = vx[idx0];
  int y0 = vy[idx0];
  int r0 = vr[idx0];
  int x1 = vx[idx1];
  int y1 = vy[idx1];
  int r1 = vr[idx1];

  int diff_x = x1 - x0;
  int diff_y = y1 - y0;
  int diff_r = r1 - r0;

  int dist_r_sqr = diff_r * diff_r;
  int dist_sqr = diff_x * diff_x + diff_y * diff_y;

  if (r0 > r1 && dist_sqr < dist_r_sqr)
    return true;
  return false;
}

bool is_child(int idx0, int idx1) {
  if (!is_in(idx0, idx1))
    return false;
  for (int i = 0; i < N; ++i) {
    if (i != idx0 && i != idx1 &&
        is_in(idx0, i) && is_in(i, idx1))
      return false;
  }
  return true;
}

Node* get_tree(int idx) {
  Node* r = new Node(idx);
  for (int i = 0; i < N; ++i) {
    if (is_child(idx, i))
      r->children.push_back(get_tree(i));
  }
  return r;
}

// get height of pnode
int height(Node* pnode) {
  // base condition
  if (pnode->children.size() == 0)
    return 0;

  std::vector<int> vh;
  for (int i = 0; i < pnode->children.size(); ++i)
    vh.push_back(height(pnode->children[i]));
  std::sort(vh.begin(), vh.end());
  if (vh.size() >= 2) {
    int maxno1 = vh.back();
    int maxno2 = vh[vh.size()-2];
    longest = std::max(longest, 2 + maxno1 + maxno2);
  }
  return vh.back() + 1;
}

// get longest distance
int solve() {
  longest = 0;

  // build tree
  Node* proot = get_tree(0);

  // get longest distance
  int h = height(proot);

  // max(longest, height)
  return std::max(h, longest);
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    scanf("%d", &N);
    vx.clear(); vx.resize(N);
    vy.clear(); vy.resize(N);
    vr.clear(); vr.resize(N);

    for (int i = 0; i < N; ++i) {
      scanf("%d %d %d", &vx[i], &vy[i], &vr[i]);
    }
    printf("%d\n", solve());
  }
  return 0;
}
