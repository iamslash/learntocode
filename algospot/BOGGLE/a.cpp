// Copyright (C) 2017 by iamslash
// https://algospot.com/judge/problem/read/BOGGLE

#include <cstdio>
#include <vector>
#include <string>

int N;
//char BOARD[5][5];
std::vector<std::string> BOARD;
const int y[8] = {1, 1, 1, 0, -1, -1, -1, 0};
const int x[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

bool IsValid(int y, int x) {
  if (y < 0 || y >= 5 || x < 0 || x >= 5)
    return false;
  return true;
}


bool Solve(int y, int x, const std::string& src, int found) {

  // base condition, invalid range
  if (!IsValid(y, x))
    return false;
  // base condition, found all
  else if (found >= src.size())
    return true;
  // base condition, wrong character
  else if (src[found] != BOARD[y][x])
    return false;

  // recursion
  for (int i = 0; i < 8; ++i) {
    
  }
  
  return true;
}

int main() {

  int T;
  scanf("%d", &T);

  for (int t = 0; t < T; ++t) {
    BOARD.clear();
    for (int i = 0; i < 5; ++i) {
      char buf[12];
      scanf("%s", buf);
      BOARD.push_back(buf);
    }

    scanf("%d", &N);

    printf("%d...\n", N);

    for (int i = 0; i < N; ++i) {
      
      char buf[12] = {0, };
      scanf("%s", buf);
      bool r = Solve(2, 2, buf, 0);
      printf("%s %s\n", buf, r ? "YES" : "NO");
    }       
  }
}


// int main() {

//   std::string v;
//   for (int i = 0; i < 5; ++i) {
//     char buf;
//     scanf("%c", buf);
//     v.push_back(buf);
//   }
//   printf("%s\n", v.c_str());  
//   return 0;
// }
