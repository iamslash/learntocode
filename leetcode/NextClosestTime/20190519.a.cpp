/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/explore/interview/card/google/67/sql-2/471/

#include <cstdio>
#include <string>
#include <algorithm>

// H0H1:M0M1

class Solution {
public:
  std::string nextClosestTime(std::string time) {
    char arr[4];
    int i;
    arr[0] = time[0];
    arr[1] = time[1];
    arr[2] = time[3];
    arr[3] = time[4];
    std::sort(std::begin(arr), std::end(arr));

    // validate M1
    for (i = 0; i < 4; ++i) {
      if (arr[i] > time[4]) {
        time[4] = arr[i];
        return time;
      }
    }

    // validate M0
    for (i = 0; i < 4; ++i) {
      if (arr[i] > time[3] && arr[i] < '6') {
        time[3] = arr[i];
        time[4] = arr[0];
        return time;
      }
    }

    // validate H1
    for (i = 0; i < 4; ++i) {
      if (arr[i] > time[1]) {
        if (time[0] != '2' || arr[i] <= '3') {
          time[1] = arr[i];
          time[3] = time[4] = arr[0];
          return time;
        }
      }
    }

    // validate H0
    for (i = 0; i < 4; ++i) {
      if (arr[i] > time[0]) {
        if (arr[i] == '1' || (arr[i] == '2' && time[i] <= '3')) {
          time[0] = arr[i];
          time[1] = time[3] = time[4] = arr[0];
          return time;
        }
      }
    }
    
    // get next day time
    time[0] = time[1] = time[3] = time[4] = arr[0];
    return time;
  }
};

int main() {
  // std::string t = "19:34"; //19:39
  std::string t = "23:59"; // 22:22
  Solution s;
  printf("%s\n", s.nextClosestTime(t).c_str());
  return 0;
}
