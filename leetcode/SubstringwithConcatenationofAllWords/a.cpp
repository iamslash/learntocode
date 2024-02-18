/* Copyright (C) 2024 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

// Time Limit Exceed
// sliding window, hash map
// O(LMN) O(N + L/M)
// - L: len of s
// - N: num of words
// - M: len of words[i]
class Solution {
public:
  vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> ans;
    int n = words.size(), m = words[0].size();
    int wndLen = n * m;
    unordered_map<string, int> wordCntMap;

    for (const auto& word : words) {
      wordCntMap[word] += 1;        
    }

    for (int i = 0; i + wndLen <= s.size(); ++i) {
      unordered_map<string, int> seenCntMap;
      int j = 0;
      // printf("i: %d\n", i);
      while (j < n) {
        string word = s.substr(i + j * m, m);

        if (wordCntMap.count(word) > 0) {
          seenCntMap[word] += 1;
          // printf("\t%s %d %d\n", word.c_str(), seenCntMap.count(word), wordCntMap.count(word));
          if (seenCntMap[word] > wordCntMap[word]) {
            break;
          }
        } else {
          break;
        }
        j++;
      }

      if (j == n) {
        ans.push_back(i);
      }
    }
    return ans;
  }
};



// words: foo bar
//        i
//     s: barfoothefoobarman
//                 l
//                 j
//  word:       ...
//  seen: bar foo
//          0   0
//   cnt: 0

// 27ms 93.25% 21.7MB 84.7%
// sliding window, hash map
// O(LMN) O(N + L/M)
// - L: len of s
// - N: num of words
// - M: len of words[i]
class Solution {
public:
  vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> ans;
 
    int n = words.size(), m = words[0].size(), wndLen = n * m;
    if (s.size() < wndLen) {
      return ans;
    }

    unordered_map<string, int> wordCntMap;
    for (const auto& word : words) {
      wordCntMap[word] += 1;
    }

    for (int i = 0; i < m; ++i) {
      int left = i, count = 0;
      unordered_map<string, int> seenCntMap;

      for (int j = i; j + m <= s.size(); j += m) {
        string word = s.substr(j, m);
        if (wordCntMap.find(word) != wordCntMap.end()) {
          seenCntMap[word]++;
          count++;

          while (seenCntMap[word] > wordCntMap[word]) {
            string leftWord = s.substr(left, m);
            seenCntMap[leftWord]--;
            left += m;
            count--;
          }

          if (count == n) {
            ans.push_back(left);
            seenCntMap[s.substr(left, m)]--;
            left += m;
            count--;
          }
        } else {
          seenCntMap.clear();
          count = 0;
          left = j + m;
        }
      }
    }
    return ans;
  }
};

int main() {
  return 0;
}
