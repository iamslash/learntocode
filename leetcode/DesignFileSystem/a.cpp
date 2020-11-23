/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <unordered_map>
#include <string>
#include <sstream>

// 268ms 52.14% 58.9MB 100.00%
// hashtable
// createPath: O(1)
// get: O(1)
class FileSystem {
 private:
  std::unordered_map<std::string, int> m_data;
 public:
  FileSystem() {
    m_data[""] = -1;
  }
    
  bool createPath(std::string path, int val) {
    std::size_t found = path.find_last_of("/\\");
    if (found == -1)
      return false;
    std::string parent = path.substr(0, found);
    if (!m_data.count(parent))
      return false;
    if (m_data.count(path))
      return false;
    m_data[path] = val;
    return true;
  }
    
  int get(std::string path) {
    if (!m_data.count(path))
      return -1;
    return m_data[path];
  }
};


int main() {

  std::string path = "/_\\df.txt";
  printf("%lu\n", path.find_last_of("/"));
  printf("%lu\n", path.find_last_of("_"));
  printf("%lu\n", path.find_last_of("\\"));
  printf("%lu\n", path.find_last_of("/_"));
  
  return 0;
}
