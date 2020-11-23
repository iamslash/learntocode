/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <sstream>

// 24ms 86.01% 15.8MB 77.78%
struct FSNode {
  std::map<std::string, FSNode*> m_path;
  std::string m_content;
  bool m_bdir=true;
  std::string m_name;
};

class FileSystem {
 private:
  FSNode* m_proot;
  FSNode* getNode(std::string path, bool bdir=true) {
    FSNode* u = m_proot;
    std::istringstream iss(path);
    std::string tok;
    while (std::getline(iss, tok, '/')) {
      if (!u->m_path.count(tok))
        u->m_path[tok] = new FSNode();
      u = u->m_path[tok];
      u->m_name = tok;
    }
    if (!bdir)
      u->m_bdir = false;
    return u;
  }
 public:
  FileSystem() {
    m_proot = new FSNode();
    m_proot->m_path[""] = new FSNode();
  }
    
  std::vector<std::string> ls(std::string path) {
    FSNode* u = getNode(path);
    if (!u->m_bdir)
      return {u->m_name};
    std::vector<std::string> r;
    for (auto& pr : u->m_path)
      r.push_back(pr.first);
    return r;
  }
    
  void mkdir(std::string path) {
    getNode(path);
  }
    
  void addContentToFile(std::string path, std::string content) {
    FSNode* u = getNode(path, false);
    u->m_content += content;
  }
    
  std::string readContentFromFile(std::string path) {
    FSNode* u = getNode(path);
    return u->m_content;
  }
};

void printls(std::vector<std::string> l) {
  for (auto& s: l)
    printf("%s ", s.c_str());
  printf("\n");
}

void prints(std::string s) {
  printf("%s\n", s.c_str());
}

int main() {

  FileSystem fs;
  printls(fs.ls("/"));
  fs.mkdir("/a/b/c");
  fs.addContentToFile("/a/b/c/d", "hello");
  printls(fs.ls("/"));
  prints(fs.readContentFromFile("/a/b/c/d"));
  printls(fs.ls("/a/b/c/d"));
  
  return 0;
}
