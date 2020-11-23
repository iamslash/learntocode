// Copyright (C) 2017 by iamslash
// https://leetcode.com/problems/word-search/description/

// Given a 2D board and a word, find if the word exists in the grid.

// The word can be constructed from letters of sequentially adjacent
// cell, where "adjacent" cells are those horizontally or vertically
// neighboring. The same letter cell may not be used more than once.

// For example,
// Given board =

// [
//  ['A','B','C','E'],
//  ['S','F','C','S'],
//  ['A','D','E','E']
// ]
// word = "ABCCED", -> returns true,
// word = "SEE", -> returns true,
// word = "ABCB", -> returns false.

#include <cstdio>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
  //   o
  // o . o
  //   o
  //
  int dy[4] = {-1, 1, 0, 0};
  int dx[4] = {0, 0, -1, 1};
    bool _exist(vector<vector<char>>& board, vector<vector<bool>>& visited, 
                int i, int j, string word) {
      // for (int k = 0; k < 6 - word.size(); ++k)
      //   printf(" ");
      // printf("[%2d][%2d]\n", i, j);
        // base condition
        if (word.size() == 0)
          return true;
        // for (int k = 0; k < 6 - word.size(); ++k)
        //   printf(" ");
        // printf("[%2d][%2d] %c : %c\n", i, j, board[i][j], word[0]);      
        if (board[i][j] != word[0])
          return false;
        if (word.size() == 1)
          return true;

        // recursion
        for (int k = 0; k < 4; ++k) {
          int ny = i + dy[k];
          int nx = j + dx[k];
          if (ny < 0 || ny >= board.size() ||
           nx < 0 || nx >= board[0].size())
            continue;
          if (visited[ny][nx] == false) {
            visited[ny][nx] = true;
            if (_exist(board, visited,
                       ny, nx, word.substr(1)))
              return true;
            visited[ny][nx] = false;
          }
        }
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited =
            vector<vector<bool>>(board.size(),
                                 vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
              // printf("%d, %d\n", i, j);
              if (visited[i][j] == false) {
                visited[i][j] = true;
                if (_exist(board, visited, i, j, word))
                    return true;
                visited[i][j] = false;
              }
            }
        }
        return false;
    }
};

int main() {
  Solution s;
  // vector<vector<char>> b = {{'A', 'B', 'C', 'E'},
  //                           {'S', 'F', 'C', 's'},
  //                           {'A', 'D', 'E', 'E'}};
  // printf("%s", s.exist(b, "ABCCED") ? "true" : "false");
  // vector<vector<char>> b = {{'a'}};
  // printf("%s", s.exist(b, "a") ? "true" : "false");
  vector<vector<char>> b = {{'a', 'b'}};
  printf("%s", s.exist(b, "ba") ? "true" : "false");
}
