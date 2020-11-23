// Copyright (C) 2018 by iamslash
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/112/design/812/

#include <cstdio>
#include <string>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(int x) :
      val(x), left(NULL), right(NULL) {};
  explicit TreeNode(int x, TreeNode* l, TreeNode* r) :
      val(x), left(l), right(r) {}
};


// 1,2,3,*,*,4,5

//   1
//  / \
// 2   3
//    / \
//   4   5
//   serialize: O(N) O(N)
// deserialize: O(N) O(N)
class Codec {
 public:

  // Encodes a tree to a single string.
  std::string serialize(TreeNode* root) {
    // base condition
    if (root == NULL)
      return "NULL";

    // recursion
    std::string r = std::to_string(root->val);
    r += ",";
    
    std::string lc = serialize(root->left);
    r +=  std::to_string(lc.size()) + ":" + lc;

    std::string rc = serialize(root->right);    
    r +=  std::to_string(rc.size()) + ":" + rc;

    return r;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(std::string d) {
    printf("%s\n", d.c_str());
    
    // base condition
    if (d.empty())
      return NULL;

    // p1 p2        
    // 1,32:NULL...,32:NULL...
    // recursion
    std::size_t posc = d.find_first_of(',');
    if (posc == std::string::npos && d == "NULL") {
      return NULL;
    }

    std::string dd = d.substr(0, posc);
    TreeNode* r = new TreeNode(std::stoi(dd));
    int posl = d.find_first_of(':');
    int lenl = std::stoi(d.substr(posc + 1, posl - posc - 1));
    r->left = deserialize(d.substr(posl + 1, lenl));

    int posr = d.find_first_of(':', posl + lenl + 1);
    int lenr = std::stoi(d.substr(posl + lenl + 1, posr - (posl + 1 + lenl)));
    r->right = deserialize(d.substr(posr + 1));
    return r;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main() {

  TreeNode* root = new TreeNode(1,
                                new TreeNode(2),
                                new TreeNode(3,
                                             new TreeNode(4),
                                             new TreeNode(5)));
  Codec c;
  // printf("%s\n", c.serialize(root).c_str());
  std::string s = "1,14:2,4:NULL4:NULL36:3,14:4,4:NULL4:NULL14:5,4:NULL4:NULL";
  printf("%s\n", c.serialize(c.deserialize(s)).c_str());

  return 0;
}
