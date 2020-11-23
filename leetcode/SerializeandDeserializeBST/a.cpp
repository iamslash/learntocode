/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <string>
#include <sstream>
#include <limits>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  explicit TreeNode(int x, TreeNode* l, TreeNode* r) :
      val(x), left(l), right(r) {}
};

     //   2
   //   /   \
   // 1       3

// 2 1 3 

// // 20ms 57.16%
// class Codec {
//  private:
//   void _serialize(TreeNode* t, std::ostringstream& oss) {
//     // base
//     if (t == NULL)
//       return;
//     oss << t->val << " ";
//     // recursion
//     _serialize(t->left, oss);
//     _serialize(t->right, oss);
//   }
//   TreeNode* _deserialize(std::istringstream& iss) {
//     std::string val;
//     iss >> val;
//     TreeNode* t = new TreeNode(std::stoi(val));
//     while (iss >> val)
//       build(t, std::stoi(val));
//     return t;
//   }
//   void build(TreeNode* t, int n) {
//     if (t->val > n) {
//       if (t->left == NULL)
//         t->left = new TreeNode(n);
//       else
//         build(t->left, n);
//     } else {
//       if (t->right == NULL)
//         t->right = new TreeNode(n);
//       else
//         build(t->right, n);
//     }
//   }
//  public:
//   // Encodes a tree to a single string.
//   std::string serialize(TreeNode* t) {
//     std::ostringstream o;
//     _serialize(t, o);
//     return o.str();
//   }

//   // Decodes your encoded data to tree.
//   TreeNode* deserialize(std::string data) {
//     if (data.empty())
//         return NULL;
//     std::istringstream iss(data);
//     return _deserialize(iss);
//   }
// };

// 20ms 57.16%
class Codec {
 private:
  inline void _serialize(TreeNode* t, std::string& r) {
    if (t == NULL)
      return;
    char buf[4];
    std::memcpy(buf, &(t->val), sizeof(int));
    for (int i = 0; i < 4; ++i)
      r.push_back(buf[i]);
    _serialize(t->left, r);
    _serialize(t->right, r);
  }
  inline TreeNode* _deserialize(const std::string& buf, int& pos, int imin, int imax) {
    // base condition
    if (pos >= buf.size())
      return NULL;

    //
    int val;
    memcpy(&val, &buf[pos], sizeof(int));
    if (val < imin || val > imax)
      return NULL;

    TreeNode* t = new TreeNode(val);
    pos += sizeof(int);
    t->left = _deserialize(buf, pos, imin, val);
    t->right = _deserialize(buf, pos, val, imax);
    return t;
  }
  
 public:
  std::string serialize(TreeNode* t) {
    std::string r;
    _serialize(t, r);
    return r;
  }

  TreeNode* deserialize(std::string data) {
    int pos = 0;
    return _deserialize(data, pos,
                        std::numeric_limits<int>::min(),
                        std::numeric_limits<int>::max());
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main() {
  TreeNode* t = new TreeNode(2,
                             new TreeNode(1),
                             new TreeNode(3));

  Codec c;
  std::string s = c.serialize(t);
  t = c.deserialize(s);

  return 0;
}
