#include <cstdio>
#include <vector>

void traverseDiagonal(std::vector<std::vector<int>>& M) {
  int h = M.size();
  int w = M[0].size();
  for (int l = 1; l < h + w; ++l) {
    int c = std::max(0, l - h);
    int n = std::min(h, std::min(l, w - c));
    for (int i = 0; i < n; ++i) {
      int y = std::min(h, l) - i - 1;
      int x = c + i;
      printf("%d ", M[y][x]);
    }
    printf("\n");
  }
}

void traverseSpiral(std::vector<std::vector<int>>& M) {
  int i;  // iterator
  int ey = M.size();  // end of y
  int ex = M[0].size();  // end of x
  int sy = 0;  // start of y
  int sx = 0;  // start of x

  while (sy < ey && sx < ex) {
    // print top row
    for (i = sx; i < ex; ++i) {
      printf("%d ", M[sy][i]);
    }
    sy++;
    // print right column
    for (i = sy; i < ey; ++i) {
      printf("%d ", M[i][ex-1]);
    }
    ex--;
    // print bottom row
    if (sy < ey) {
      for (i = ex-1; i >= sx; --i) {
        printf("%d ", M[ey-1][i]);
      }
      ey--;
    }
    // print left column
    if (sx < ex) {
      for (i = ey-1; i >= sy; --i) {
        printf("%d ", M[i][sx]);
      }
      sx++;
    }    
  }
}

int main() {

  std::vector<std::vector<int>> V = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    {13, 14, 15, 16},
    {17, 18, 19, 20},
  };

  traverseDiagonal(V);
  
  return 0;
}
