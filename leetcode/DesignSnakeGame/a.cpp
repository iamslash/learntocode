/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_map>
#include <deque>
#include <string>

// 292ms 16.36% 84.4MB 5.72%
// O(S) O(S)
// S: length of snake
class SnakeGame {
 private:
  int m_h;
  int m_w;
  int m_i; // food index
  std::vector<std::pair<int, int>> m_food;
  std::deque<std::pair<int, int>> m_snake;
 public:
  SnakeGame(int width, int height, std::vector<std::pair<int, int>>& food) {
    m_h = height;
    m_w = width;
    m_food = food;
    m_i = 0;
    m_snake.push_back({0, 0});
  }
    
  int move(std::string dir) {
    std::unordered_map<std::string, std::pair<int, int>> coords = {
      {"U", {-1,  0}},
      {"R", { 0,  1}},
      {"D", { 1,  0}},
      {"L", { 0, -1}}
    };
    int ny = m_snake.front().first  + coords[dir].first;
    int nx = m_snake.front().second + coords[dir].second;
    // check direction to body ???
    // check boundary
    if (ny < 0 || ny >= m_h || nx < 0 || nx >= m_w)
      return -1;

    // check food
    if (m_i < m_food.size() &&
        ny == m_food[m_i].first &&
        nx == m_food[m_i].second) {
      m_snake.push_front({ny, nx});
      return ++m_i;
    }

    // check body
    m_snake.pop_back();
    for (auto pr : m_snake) {
      if (ny == pr.first && nx == pr.second)
        return -1;
    }

    // just move
    m_snake.push_front({ny, nx});

    return m_i;
  }
};

int main() {
  std::vector<std::pair<int, int>> food = {
    {1, 2},
    {0, 1}
  };
  int h = 2;
  int w = 3;

  SnakeGame sg(w, h, food);
  printf("%d\n", sg.move("R")); 
  printf("%d\n", sg.move("D")); 
  printf("%d\n", sg.move("R")); 
  printf("%d\n", sg.move("U")); 
  printf("%d\n", sg.move("L")); 
  printf("%d\n", sg.move("U")); 
  
  return 0;
}
