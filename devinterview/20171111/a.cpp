
// Copyright (C) 2017 by iamslash
// https://leetcode.com/problems/minimum-window-substring/description/
// http://www.geeksforgeeks.org/find-the-smallest-window-in-a-string-containing-all-characters-of-another-string/

// Given a string S and a string T, find the minimum window in S witch
// will contain all the characters in T in complexity O(n).

// For example,
// S = “ADOBECODEBANC”
// T = “ABC”
// minimum window is “BANC”

// S = “bba”
// T = “ab”
// minimum window is “ba”

// If there is no such window in S that covers all characters in T,
// return the empty string “”;

// if there are multiple such windows, you are guaranteed that there
// will always be only one unique minimum window in S.

//  t  f
// “ADOBECODEBANC”
// "ABC"

#include <cstdio>
#include <string>
#include <vector>


const int MAX_INT = 987654321;

class Solution {
 public:
  std::string minWindow(std::string s, std::string t) {
    int matched = 0;
    int s_cnt[256] = {0,};
    int t_cnt[256] = {0,};
    int fr_idx_min = -1;
    int len_min = MAX_INT;
    int fr_idx = 0;

    // validate s length
    if (s.size() < t.size())
      return "";

    // set t_cnt
    for (int i = 0; i < t.size(); ++i) {
      t_cnt[t[i]]++;
    }

    // traverse s to make a min window
    for (int to_idx = 0; to_idx < s.size(); ++to_idx) {
      // c is in t
      char to_c = s[to_idx];
      s_cnt[to_c]++;
      if (t_cnt[to_c] > 0 && s_cnt[to_c] <= t_cnt[to_c])
        matched++;
      
      // printf("%2d s_cnt: %d t_cnt: %d matched: %d\n", to_idx, s_cnt[to_c], t_cnt[to_c], matched);
      if (matched == t.size()) {
        // move left idx of window
        char fr_c = s[fr_idx];
        while (t_cnt[fr_c] == 0 || s_cnt[fr_c] > t_cnt[fr_c]) {
          // printf("%2d fr_c: %c s_cnt: %d t_cnt: %d matched: %d\n", fr_idx, fr_c, s_cnt[fr_c], t_cnt[fr_c], matched);
          if (s_cnt[fr_c] > t_cnt[fr_c])
            s_cnt[fr_c]--;
          fr_c = s[++fr_idx];
        }
        // set len_min
        int len_cur = to_idx - fr_idx + 1;
        if (len_cur < len_min) {
          fr_idx_min = fr_idx;
          len_min = len_cur;
        }
        printf("%2d s_cnt: %d t_cnt: %d matched: %d\n", to_idx, s_cnt[to_c], t_cnt[to_c], matched);       
      }      
    }

    // There is no window
    if (fr_idx_min < 0)
      return "";

    return s.substr(fr_idx_min, len_min);
  }
};

int main() {
  Solution s;
  printf("%s\n", s.minWindow("ADOBECODEBANC", "ABC").c_str());
}
