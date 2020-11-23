/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 174ms 66.73% 55MB 80.16%
// linear traversal
// visit: O(N) O(N)
class BrowserHistory {
 private:
  vector<string> hist;
  int pos = 0;
 public:
  BrowserHistory(string url) {        
    hist.push_back(url);
    pos = 0;
  }      
  void visit(string url) {
    pos++;    
    hist.resize(pos);
    hist.push_back(url);
  }
    
  string back(int steps) {
    pos = max(0, pos - steps);
    return hist[pos];
  }
    
  string forward(int steps) {
    pos = min((int)hist.size()-1, pos + steps);
    return hist[pos];
  }
};
