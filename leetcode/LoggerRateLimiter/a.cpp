#include <cstdio>
#include <string>
#include <unordered_map>

// 128ms 8.21% 32.9MB 45.94%
// Q. msg has blanks as prefix, postfix?
// O(1) O(N)
class Logger {
 private:
  std::unordered_map<std::string, int> m_ump;
 public:
  Logger() {
        
  }
    
  bool shouldPrintMessage(int ts, string s) {
    if (m_ump.count(s) > 0 && ts - m_ump[s] < 10)
      return false;
    m_ump[s] = ts;
    return true;
  }
};