/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 260ms 64.98% 40.9MB 100.00%
// array
// O(N) O(N)
class TweetCounts {
 private:
  unordered_map<string, vector<int>> data;
 public:
  TweetCounts() {
    
  }
    
  void recordTweet(string tweet, int time) {
    data[tweet].push_back(time);
  }
    
  vector<int> getTweetCountsPerFrequency(string freq, string tweet, int start, int end) {
    int unit = 1;
    if (freq == "minute")
      unit = 60;
    else if (freq == "hour")
      unit = 3600;
    else if (freq == "day")
      unit = 86400;
    vector<int> ans;
    for (int i = 0; i <= (end - start) / unit; ++i)
      ans.push_back(0);
    for (int time : data[tweet]) {
      if (start <= time && time <= end) {
        int i = (time - start) / unit;
        ans[i]++;
      }
    }
    return ans;
  }
};

