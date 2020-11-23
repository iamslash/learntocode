/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/explore/interview/card/top-interview-questions-hard/116/array-and-strings/831/

#include <cstdio>
#include <vector>

class Solution {
 public:
  int get_lives(std::vector<std::vector<int>>& B, int i, int j) {
    int r = 0;
    std::vector<std::pair<int, int>> D = {
      {-1, -1},
      {-1,  0},
      {-1,  1},
      { 0,  1},
      { 1,  1},
      { 1,  0},
      { 1, -1},
      { 0, -1}
    };
    for (const auto& d : D) {
      int y = i + d.first;
      int x = j + d.second;
      if (y < 0 || y >= B.size() ||
          x < 0 || x >= B[0].size())
        continue;
      if (B[y][x] & 0x01)
        ++r;
    }
    return r;
  }
  void gameOfLife(std::vector<std::vector<int>>& B) {
    for (int i = 0; i < B.size(); ++i) {
      for (int j = 0; j < B[0].size(); ++j) {
        int lives = get_lives(B, i, j);
        if (B[i][j]) {
          if (lives == 2 || lives == 3)
            B[i][j] = 0x03; // 11
          else
            B[i][j] = 0x01; // 01
        } else {
          if (lives == 3)
            B[i][j] |= 0x02; // 10
        }
        // printf("%d ", B[i][j]);
      }
      // printf("\n");
    }
    for (int i = 0; i < B.size(); ++i) {
      for (int j = 0; j < B[0].size(); ++j) {
        B[i][j] >>= 1;
      }
    }
  }
}; 

// [[0,1,0,0,1,1,0],
//  [1,1,1,1,1,1,1],
//  [1,1,0,0,0,0,1],
//  [1,1,0,0,1,0,0]]

// [[1,1,0,0,0,0,0],
//  [0,0,0,0,0,0,0],
//  [0,0,0,0,0,0,0],
//  [1,1,0,0,0,0,0]]
//
// [[1,1,0,0,0,0,1],
//  [0,0,0,1,0,0,1],
//  [0,0,0,0,0,0,1],
//  [1,1,0,0,0,0,0]]
int main() {
  Solution s;
  // std::vector<std::vector<int>> B = {
  //   {0, 1, 0},
  //   {0, 0, 1},
  //   {1, 1, 1},
  //   {0, 0, 0}    
  // };
  std::vector<std::vector<int>> B = {
    {0, 1, 0, 0, 1, 1, 0},
    {1, 1, 1, 1, 1, 1, 1},
    {1, 1, 0, 0, 0, 0, 1},
    {1, 1, 0, 0, 1, 0, 0}    
  };

  
  s.gameOfLife(B);
  for (int i = 0; i < B.size(); ++i) {
    for (int j = 0; j < B[0].size(); ++j) {
      printf("%d ", B[i][j]);
    }
    printf("\n");
  }  
  return 0;
}
