#include <cstdio>
#include <vector>
#include <map>
#include <queue>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

// 8ms 98.03% 9.8MB 94.68%
// BFS
// O(N) O(N)
class Solution {
 public:
  std::vector<std::vector<int>> verticalOrder(TreeNode* u) {
    if (!u)
      return {};
    std::vector<std::vector<int>> rslt;
    std::map<int, std::vector<int>> smp;
    std::queue<std::pair<int, TreeNode*>> q;
    q.push({0, u});
    while(q.size()) {
      int n = q.size();
      for (int i = 0; i < n; ++i) {
        auto pr = q.front(); q.pop();
        int idx = pr.first;
        TreeNode* v = pr.second;
        smp[idx].push_back(v->val);
        if (v->left)
          q.push({idx-1, v->left});
        if (v->right)
          q.push({idx+1, v->right});
      }
    }
    for (auto& v : smp)
      rslt.push_back(v.second);
    return rslt;
  }
};

int main() {
  // [1,null,4,3,5,2,null,null,6]
  TreeNode* u = new TreeNode(3, new TreeNode(9),
                  new TreeNode(20, new TreeNode(15), new TreeNode(7)));
  Solution sln;
  auto r = sln.verticalOrder(u);
  for (auto& l : r) {
    for (int a : l)
      printf("%d ", a);
    printf("\n");
  }
  return 0;
}
