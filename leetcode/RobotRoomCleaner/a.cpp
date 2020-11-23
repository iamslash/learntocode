/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <set>

class Robot {
 public:
  bool move();
  void turnLeft();
  void turnRight();
  void clean();
};

// 16ms 91.76% 11.2MB 67.74%
// DFS
class Solution {
 private:
  // clean status of cell
  std::set<std::pair<int, int>> m_seen;
  void back(Robot& robot) {
    robot.turnRight();
    robot.turnRight();
    robot.move();
    robot.turnRight();
    robot.turnRight();    
  }
  void dfs(Robot& robot, int y, int x, int dir) {
    m_seen.insert({y, x});
    robot.clean();
    
    int dy[4] = {-1, 0, 1,  0};
    int dx[4] = { 0, 1, 0, -1};

    // recursion
    for (int i = 0; i < 4; ++i) {
      int ny = y + dy[dir];
      int nx = x + dx[dir];

      if (m_seen.count({ny, nx}) == 0 && robot.move()) {
        dfs(robot, ny, nx, dir);
      }
      robot.turnRight();
      ++dir;
      dir %= 4;
    }
    back(robot);
  }
 public:
  void cleanRoom(Robot& robot) {
    dfs(robot, 0, 0, 0);
  }
};

int main() {
  return 0;
}
