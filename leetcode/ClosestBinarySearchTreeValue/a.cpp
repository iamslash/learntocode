#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cfloat>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 20ms 71.35% 20.4MB 86.15%
// O(N) O(1)
class Solution {
 public:
  int closestValue(TreeNode* u, double tgt) {
    // base 
    if (u == NULL)
      return INT_MAX;

    // recursion
    int mval = u->val;
    double mdst = std::fabs(u->val - tgt);

    int    lval = closestValue(u->left, tgt);
    double ldst = (lval == INT_MAX) ? DBL_MAX : std::fabs(lval - tgt);

    if (ldst < mdst) {
      mval = lval;
      mdst = ldst;
    }    

    int rval = closestValue(u->right, tgt);
    double rdst = (rval == INT_MAX) ? DBL_MAX : std::fabs(rval - tgt);

    if (rdst < mdst) {
      mval = rval;
      mdst = rdst;
    }
    
    return mval;
  }
};

// 28ms 13.16% 20.5MB 65.38%
// O(lgN) O(1)
class Solution {
 private:
  double m_dst = DBL_MAX;
  int m_val = 0;
  void solve(TreeNode* u, double tgt) {
    // base
    if (u == NULL)
      return ;

    // recursion
    double dst = std::fabs(tgt - u->val);
    if (dst < m_dst) {
      m_dst = dst;
      m_val = u->val;
    }
    if (tgt < u->val)
      solve(u->left, tgt);
    if (tgt > u->val)
      solve(u->right, tgt);
  }
 public:
  int closestValue(TreeNode* u, double tgt) {
    solve(u, tgt);
    return m_val;
  }
};

int main() {
  return 0;
}