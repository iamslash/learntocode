// Copyright (C) 2016 by iamslash
// https://algospot.com/judge/problem/read/FORTRESS

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

int N;
std::vector<int> v_x;
std::vector<int> v_y;
std::vector<int> v_r;

// 지금까지 찾은 가장 긴 잎-잎 경로의 길이를 저장한다.
int longest;

struct TreeNode {
  std::vector<TreeNode*> children;
};

void print_v_int(const std::vector<int>& g) {
  // printf(" <----\n");
  for (int i=0; i < g.size(); ++i) {
    printf("%4d ", g[i]);
  }
  printf("\n");
}

int sqr(int x) {
  return x * x;
}

int sqrdist(int a, int b) {
  return sqr(v_x[a] - v_x[b]) + sqr(v_y[a] - v_y[b]);
}

bool enclose(int a, int b) {
  return v_r[a] > v_r[b] &&
      sqrdist(a, b) < sqr(v_r[a] - v_r[b]);
}

bool is_child(int parent, int child) {
  if (!enclose(parent, child))
    return false;
  // 간접적으로 포함하는 것인지 조사해 본다.
  for (int i = 0; i < N; ++i) {
    if (i != parent && i != child &&
        enclose(parent, i) && enclose(i, child))
      return false;
  }
  return true;
}

TreeNode* get_tree(int root) {
  TreeNode* r = new TreeNode();
  for (int ch = 0; ch < N; ++ch) {
    if (is_child(root, ch))
      r->children.push_back(get_tree(ch));
  }
  return r;
}

// root틀 루트로 하는 서브트리의 높이를 계산한다.
int height(TreeNode* root) {
  std::vector<int> heights;

  // recursion
  for (int i = 0; i < root->children.size(); ++i)
    heights.push_back(height(root->children[i]));

  // base condition
  if (heights.empty())
    return 0;
  std::sort(heights.begin(), heights.end());

  if (heights.size() >= 2)
    longest = std::max(longest, 2 + heights[heights.size() - 2] +
                       heights[heights.size() - 1]);
  return heights.back() + 1;
}

// 두 노드 사이의 가장 긴 경로의 길이를 계산한다.
int solve(TreeNode* root) {
  longest = 0;
  int h = height(root);
  return std::max(longest, h);
}

int main() {
  int T;
  std::cin >> T;

  for (int t = 0; t < T; ++t) {
    std::cin >> N;
    v_x.resize(N);
    v_y.resize(N);
    v_r.resize(N);

    for (int i = 0; i < N; ++i) {
      scanf("%d %d %d", &v_x[i], &v_y[i], &v_r[i]);
    }

    // print_v_int(v_x);
    // print_v_int(v_y);
    // print_v_int(v_r);

    TreeNode* root = get_tree(0);

    printf("%d\n", solve(root));
  }
  //
  return 0;
}
