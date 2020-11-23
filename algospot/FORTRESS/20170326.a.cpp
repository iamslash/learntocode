// Copyright (C) 2016 by iamslash
// https://algospot.com/judge/problem/read/FORTRESS

#include <cstdio>
#include <cmath>
#include <vector>

int N;
std::vector<int> vx;
std::vector<int> vy;
std::vector<int> vr;

class TreeNode {
 public:
  int idx;
  int height;
  std::vector<TreeNode*> children;
  explicit TreeNode(int _idx, int _height) : idx(_idx), height(_height) {}
};

// is idx_dst is included in idx_src???
bool is_in(int idx_src, int idx_dst) {
  int src_x = vx[idx_src];
  int src_y = vy[idx_src];
  int src_r = vr[idx_src];
  int dst_x = vx[idx_dst];
  int dst_y = vy[idx_dst];
  int dst_r = vr[idx_dst];

  int diff_x = src_x - dst_x;
  int diff_y = src_y - dst_y;
  int dist = sqrt(diff_x * diff_x + diff_y * diff_y);

  if (dist + dst_r <= src_r)
    return true;
  return false;
}

int insert(TreeNode* pnode, TreeNode* pnew) {
  // recursion
  for (int i = 0; i < pnode->children.size(); ++i) {
    TreeNode* pchild = pnode->children[i];
    if (is_in(pchild->idx, pnew->idx)) {
      return insert(pchild, pnew);
    }
  }

  // base condition
  pnode->children.push_back(pnew);
  pnew->height = pnode->height + 1;
  // printf("  %d %d %d\n", pnode->idx, pnew->idx, pnew->height);
  return pnew->height;
}

int solve() {
  int maxh0 = 0, maxh1 = 0;

  TreeNode* proot = new TreeNode(0, 0);
  for (int i = 1; i < N; ++i) {
    TreeNode* pchild = new TreeNode(i, 0);
    int h = insert(proot, pchild);
    if (maxh1 < h) {
      maxh0 = maxh1;
      maxh1 = h;
    } else if (maxh0 < h && maxh1 > h) {
      maxh0 = h;
    }
  }

  printf("%d %d\n", maxh0, maxh1);

  return maxh0 + maxh1;
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
      int x, y, r;
      scanf("%d %d %d", &vx[i], &vy[i], &vr[i]);
    }
    printf("%d\n", solve());
  }

  return 0;
}

