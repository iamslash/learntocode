/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <map>

// 4ms 99.33%
// O(1) O(N)
class Solution {
 private:
  std::string m_base = "http://tinyurl.com/";
  std::map<std::string, int> m_url2num;
  std::map<int, std::string> m_num2url;
 public:
  std::string encode(std::string longUrl) {
    int num;
    if (m_url2num.count(longUrl) == 0) {
      num = m_url2num.size();
      m_url2num[longUrl] = num;
      m_num2url[num] = longUrl;
    } else {
      num = m_url2num[longUrl];
    }
    return m_base + std::to_string(num);
  }
  std::string decode(std::string shortUrl) {
    shortUrl = shortUrl.substr(m_base.size());
    int num = std::stoi(shortUrl);
    if (m_num2url.count(num))
      return m_num2url[num];
    return "";
  }
};

int main() {
  Solution sln;
  std::string s = "https://leetcode.com/problems/design-tinyurl";
  printf("%s\n", sln.encode(s).c_str());
  printf("%s\n", sln.decode(sln.encode(s)).c_str());
  
  return 0;
}
