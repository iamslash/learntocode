/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// // 52ms 88.84% 10.5MB 100.00%
// // Exhaustive Search
// // O(N^2) O(1)
// class Solution {
//  public:
//   int minArea(std::vector<std::vector<char>>& G, int ox, int oy) {
//     int h = G.size();
//     int w = G[0].size();
//     int sy = h;
//     int ey = 0;
//     int sx = w;
//     int ex = 0;    
    
//     for (int y = 0; y < h; ++y) {
//       for (int x = 0; x < w; ++x) {
//         if (G[y][x] == '1') {
//           sy = std::min(sy, y);
//           ey = std::max(ey, y);
//           sx = std::min(sx, x);
//           ex = std::max(ex, x);
//           // printf("%d, %d, sy:%d, ey:%d, sx:%d, ex:%d\n", y, x, sy, ey, sx, ex);
//         }
//       }
//     }    
//     return (ey-sy+1) * (ex-sx+1);
//   }
// };


// Binary Search
// 52ms 88.84% 10.5MB 100.00%
class Solution {
 private:
  int searchCols(std::vector<std::vector<char>>& G,
                 int i, int j, int t, int b, bool w2b) {
    while (i != j) {
      int k = t;
      int m = (i+j)/2;
      while (k < b && G[k][m] == '0')
        ++k;
      if (k < b == w2b)
        j = m;
      else
        i = m + 1;
    }
    return i;
  }
  int searchRows(std::vector<std::vector<char>>& G,
                 int i, int j, int l, int r, bool w2b) {
    while (i != j) {
      int k = l;
      int m = (i+j)/2;
      while(k < r && G[m][k] == '0')
        ++k;
      if (k < r == w2b)
        j = m;
      else
        i = m + 1;
    }
    return i;
  }  
 public:
  int minArea(std::vector<std::vector<char>>& G, int x, int y) {
    int h = G.size();
    int w = G[0].size();
    int l = searchCols(G, 0, y, 0, h, true);
    int r = searchCols(G, y+1, w, 0, h, false);
    int t = searchRows(G, 0, x, l, r, true);
    int b = searchRows(G, x+1, h, l, r, false);

    return (r-l) * (b-t);
  }
};

int main() {
  std::vector<std::vector<char>> G =
  {
    {'0', '0', '1', '0'},
    {'0', '1', '1', '0'},
    {'0', '1', '0', '0'},
  };
  int x = 0;
  int y = 2;

  Solution sln;
  printf("%d\n", sln.minArea(G, x, y));
  
  return 0;
}
