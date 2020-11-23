/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <map>
#include <vector>
#include <string>

// 24ms 100.00% 14.3MB 86.67%
//      put: O(lgN) O(N)
// retrieve: O(1) O(N) 
class LogSystem {
 private:
  std::multimap<std::string, int> m_smp;
 public:
  LogSystem() {
  }
    
  void put(int id, std::string ts) {
    m_smp.emplace(ts, id);
  }

  // Year:Month:Day:Hour:Minute:Second
  std::vector<int> retrieve(std::string s, std::string e, std::string gra) {
    if (gra == "Year") {
      s = s.substr(0, 4) + ":01:01:00:00:00";
      e = e.substr(0, 4) + ":12:31:23:59:59";
    } else if (gra == "Month") {
      s = s.substr(0, 7) + ":01:00:00:00";
      e = e.substr(0, 7) + ":31:23:59:59";
    } else if (gra == "Day") {
      s = s.substr(0, 10) + ":00:00:00";
      e = e.substr(0, 10) + ":23:59:59";      
    } else if (gra == "Hour") {
      s = s.substr(0, 13) + ":00:00";
      e = e.substr(0, 13) + ":59:59";      
    } else if (gra == "Minute") {
      s = s.substr(0, 16) + ":00";
      e = e.substr(0, 16) + ":59";      
    } 
    auto its = m_smp.lower_bound(s);
    auto ite = m_smp.upper_bound(e);
    std::vector<int> rslt;
    for (auto it = its; it != ite; ++it) {
      rslt.push_back(it->second);
    }
    return rslt;
  }
};

void printv(std::vector<int> V) {
  for (int a : V) {
    printf("%d ", a);
  }
  printf("\n");
}

int main() {

  LogSystem ls;
  ls.put(1, "2017:01:01:23:59:59");
  ls.put(2, "2017:01:01:22:59:59");
  ls.put(3, "2016:01:01:00:00:00");
  printv(ls.retrieve("2016:01:01:01:01:01","2017:01:01:23:00:00","Year")); // return [1,2,3], because you need to return all logs within 2016 and 2017.
  printv(ls.retrieve("2016:01:01:01:01:01","2017:01:01:23:00:00","Hour")); // return [1,2], because you need to return all logs start from 2016:01:01:01 to 2017:01:01:23, where log 3 is left outside the range.  
  return 0;
}
