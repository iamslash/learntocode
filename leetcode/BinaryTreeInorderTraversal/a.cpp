/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <stack>

     //      1
     //     / \
     //   2c   3
     //  /  \  / \
     // 4p  5 6   7
// s:   
// p: 3
// 4 2 5 1
// 4 2 5 1 6 3 7
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

// // recursion
// // O(N), O(N)
// class Solution {
// public:
//   std::vector<int> r;
//   void _traverse(TreeNode* node) {
//     // base condition
//     if (node == NULL)
//       return;
    
//     // recursion
//     if (node->left)
//       _traverse(node->left);
//     r.push_back(node->val);
//     if (node->right)
//       _traverse(node->right);
//   }
//   std::vector<int> inorderTraversal(TreeNode* root) {
//     _traverse(root);
//     return r;
//   }
// };

// // stack
// // O(N), O(N)
// // 4ms
// class Solution {
//  public:
//   std::vector<int> inorderTraversal(TreeNode* root) {
//     std::vector<int> rslt;
//     if (!root)
//       return rslt;
//     std::stack<TreeNode*> stck;
//     TreeNode* p = root;
//     while (p || !stck.empty()) {
//       if (p) {
//         stck.push(p);
//         p = p->left;
//       } else {
//         p = stck.top(); stck.pop();
//         rslt.push_back(p->val);
//         p = p->right;
//       }
//     }
//     return rslt;
//   }
// };

// morris traversal
// O(N), O(1)
class Solution {
 public:
  std::vector<int> inorderTraversal(TreeNode* root) {
    TreeNode* p = root;
    std::vector<int> rslt;
    while (p) {
      if (p->left) {
        TreeNode* pre = p->left;
        while (pre->right && (pre->right != p))
          pre = pre->right;
        if (pre->right == NULL) {
          pre->right = p;
          p = p->left;
        } else {
          pre->right = NULL;
          rslt.push_back(p->val);
          p = p->right;
        }
      } else {
        rslt.push_back(p->val);
        p = p->right;
      }
    }
    return rslt;
  }
};

int main() {

  TreeNode* root = new TreeNode(1,
                                NULL,
                                new TreeNode(2,
                                             new TreeNode(3),
                                             NULL));                                

  Solution sln;
  auto rslt = sln.inorderTraversal(root);

  for (int a : rslt)
    printf("%d ", a);
  printf("\n");
  
  return 0;
}
