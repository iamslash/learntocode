/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>

// http://

class HtmlParser {
 public:
  std::vector<std::string> getUrls(std::string url);
};

// 84ms 57.95% 36.8MB 100.00%
// BFS
// O(N) O(N)
class Solution {
 private:
  std::string getHostname(const std::string& url) {
    std::string::size_type found = url.find_first_of("/", 7);
    return url.substr(0, found);
  }
 public:
  std::vector<std::string> crawl(std::string startUrl, HtmlParser htmlParser) {
    std::queue<std::string> bfsq;
    std::unordered_set<std::string> seen;
    std::string hostName = getHostname(startUrl);
    bfsq.push(startUrl);
    seen.insert(startUrl);
    while (bfsq.size()) {
      std::string uUrl = bfsq.front(); bfsq.pop();
      for (std::string vUrl : htmlParser.getUrls(uUrl)) {
        if (getHostname(vUrl) == hostName &&
            seen.find(vUrl) == seen.end()) {
          bfsq.push(vUrl);
          seen.insert(vUrl);
        }
      }
    }
    return std::vector<std::string>(seen.begin(), seen.end());
  }
};

int main() {
  return 0;
}
