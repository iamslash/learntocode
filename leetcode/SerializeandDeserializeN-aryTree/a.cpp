/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <string>
#include <sstream>

class Node {
 public:
  int val = 0;
  std::vector<Node*> children;
  Node() {}
  Node(int _val, std::vector<Node*> _children) {
    val = _val;
    children = _children;
  }
};

// " 1 3 3 2 5 0 6 0 2 0 4 0"

// 248ms 79,81% 47MB 78.18%
class Codec {

 private:
  void encode(Node* u, std::string& s) {
    if (!u)
      return;
    s += " " + std::to_string(u->val) + " " +
        std::to_string(u->children.size());
    for (auto* p : u->children)
      encode(p, s);
  }
  Node* decode(std::stringstream& ss) {
    ss.peek();
    if (ss.eof())
      return NULL;
    auto u = new Node();
    int nv;
    ss >> u->val >> nv;
    for (int i = 0; i < nv; ++i)
      u->children.push_back(decode(ss));
    return u;
  }
 public:
  // Encodes a tree to a single string.
  std::string serialize(Node* u) {
    std::string s;
    encode(u, s);
    return s;
  }

  // Decodes your encoded data to tree.
  Node* deserialize(std::string s) {
    std::stringstream ss(s);
    return decode(ss);
  }
};
//                    i
//     j
// [1:3[3:2[5:0][6:0]][2:0][4:0]]

int main() {
  
  return 0;
}
