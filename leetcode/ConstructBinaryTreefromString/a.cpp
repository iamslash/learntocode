/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 40ms 96.32% 23.3MB 80.00%
//  O(N) O(N)
class Solution {
 private:
  int m_i;
  TreeNode* solve(std::string& s) {
    int beg = m_i;
    if (s[m_i] == '-')
      ++m_i;
    while (std::isdigit(s[m_i]))
      ++m_i;
    int val = std::stoi(s.substr(beg, m_i - beg));
    TreeNode* u = new TreeNode(val);
    if (s[m_i] == '(') {
      ++m_i;
      u->left = solve(s);
      ++m_i;
    }
    if (s[m_i] == '(') {
      ++m_i;
      u->right = solve(s);
      ++m_i;
    }
    return u;
  }
 public:
  TreeNode* str2tree(std::string s) {
    if (s.empty())
      return NULL;
    m_i = 0;
    return solve(s);
  }
};

//   i
// 4(2(3)(1))(6(5))

int main() {
  return 0;
}
