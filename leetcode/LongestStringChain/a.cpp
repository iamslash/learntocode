#include <cstdio>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 208ms 42.89% 50.2MB 24.88%
// sort, hash map
// O(N) O(N)
class Solution {
 public:
  int longestStrChain(vector<string>& words) {
    sort(words.begin(), words.end(), [](const string& a, const string& b) {
      return a.size() < b.size();
    });
    int glbmax = 0;
    unordered_map<string, int> C;
    for (string& s : words) {
      int locmax = 0;
      for (int i = 0; i < s.size(); ++i) {
        string t = s.substr(0, i) + s.substr(i+1);
        locmax = max(locmax, C[t] + 1);
      }
      C[s] = locmax;
      glbmax = max(glbmax, locmax);
    }
    return glbmax;
  }
};
