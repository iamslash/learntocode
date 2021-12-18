// 0ms 100.00% 39MB 7.27%
// brute force
// O(N) O(1)
class Solution {
  public boolean isRobotBounded(String instructions) {
    int[] dirs = new int[]{-1, 0, 1, 0, -1};
    int i = 0, y = 0, x = 0;
    for (char inst : instructions.toCharArray()) {
      if (inst == 'L') {
        i = (i + 3) % 4;
      } else if (inst == 'R') {
        i = (i + 1) % 4;
      } else {
        y += dirs[i];
        x += dirs[i+1];
      }
    }
    return (y == 0 && x == 0) || i > 0;
  }
}
