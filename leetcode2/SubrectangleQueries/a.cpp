/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

// 100ms 52.50% 19.4MB 100.00%
// updateSubrectangle: O(1) O(N)
// getvalue: O(H) O(N)
class SubrectangleQueries {
 private:
  vector<vector<int>> data;
  vector<vector<int>> hist;
 public:
  SubrectangleQueries(vector<vector<int>>& rect) {
    data = rect;
  }
    
  void updateSubrectangle(int a, int b, int c, int d, int val) {
    hist.push_back({a, b, c, d, val});
  }
    
  int getValue(int y, int x) {
    for (int i = hist.size() - 1; i >= 0; --i) {
      auto& h = hist[i];
      if (y >= h[0] && y <= h[2] && x >= h[1] && x <= h[3])
        return h[4];
    }
    return data[y][x];
  }
};
