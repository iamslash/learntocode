/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <string>

using namespace std;

// 72ms 14.71% 14.4MB 70.59%
// binary search
// O(TlgF) O(1)
class Solution {
 private:
  bool isOut(string& text, int w, int h, int sz, FontInfo& fontInfo) {
    int64_t wsum = 0;
    for (int c : text) {
      wsum += fontInfo.getWidth(sz, c);
    }
    return wsum > w || fontInfo.getHeight(sz) > h;
  }
 public:
  int maxFont(string& text, int w, int h,
              vector<int>& fonts, FontInfo& fontInfo) {
    int n = fonts.size();
    int lo = -1, hi = n - 1, mi;
    while (lo < hi) {
      mi = max(lo + 1, lo + (hi - lo) / 2);
      if (isOut(text, w, h, fonts[mi], fontInfo)) {
        hi = mi - 1;
      } else {
        lo = mi;
      }
    }
    return (lo == -1) ? -1 : fonts[lo];
  }
};


// 68ms 32.35% 14.4MB 70.59%
// binary search
// O(TlgF) O(1)
class Solution {
 private:
  unordered_map<char, int> cntMap;
  bool isOut(string& text, int w, int h, int sz, FontInfo& fontInfo) {
    int64_t wsum = 0;
    for (auto& pr : cntMap) {
      wsum += fontInfo.getWidth(sz, pr.first) * pr.second;
    }
    return wsum > w || fontInfo.getHeight(sz) > h;
  }
 public:
  int maxFont(string& text, int w, int h,
              vector<int>& fonts, FontInfo& fontInfo) {
    for (char c : text)
      cntMap[c]++;
    int n = fonts.size();
    int lo = -1, hi = n - 1, mi;
    while (lo < hi) {
      mi = max(lo + 1, lo + (hi - lo) / 2);
      if (isOut(text, w, h, fonts[mi], fontInfo)) {
        hi = mi - 1;
      } else {
        lo = mi;
      }
    }
    return (lo == -1) ? -1 : fonts[lo];
  }
};

// 64ms 67.65% 14.3MB 70.59%
// binary search
// O(TlgF) O(1)
class Solution {
 private:
  vector<int> cnts;
  bool isOut(string& text, int w, int h, int sz, FontInfo& fontInfo) {
    int64_t wsum = 0;
    for (int i = 0; i < 26; ++i) {
      wsum += cnts[i] * fontInfo.getWidth(sz, 'a'+i);
    }
    return wsum > w || fontInfo.getHeight(sz) > h;
  }
 public:
  int maxFont(string& text, int w, int h,
              vector<int>& fonts, FontInfo& fontInfo) {
    cnts.resize(26);
    for (char c : text)
      cnts[c-'a']++;
    int n = fonts.size();
    int lo = -1, hi = n - 1, mi;
    while (lo < hi) {
      mi = max(lo + 1, lo + (hi - lo) / 2);
      if (isOut(text, w, h, fonts[mi], fontInfo)) {
        hi = mi - 1;
      } else {
        lo = mi;
      }
    }
    return (lo == -1) ? -1 : fonts[lo];
  }
};
