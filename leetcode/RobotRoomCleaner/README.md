# Problem

[Robot Room Cleaner](https://leetcode.com/problems/robot-room-cleaner/)

`Robot robot` 이 주어진다. `Robot` 은 다음과 같다.

```java
interface Robot {
  // returns true if next cell is open and robot moves into the cell.
  // returns false if next cell is obstacle and robot stays on the current cell.
  boolean move();

  // Robot will stay on the same cell after calling turnLeft/turnRight.
  // Each turn will be 90 degrees.
  void turnLeft();
  void turnRight();

  // Clean the current cell.
  void clean();
}
```

한 지점을 출발하여 모든 방을 청소하도록 구현하라.

# Idea

[DFS](/fundamentals/graph/dfs/README.md) 를 이용하여 구현한다.

다음과 같은 부분문제 `dfs` 를 정의한다.

```c
void dfs(y, x, d)

y: y of pos
x: x of pos
d: direction 0, 1, 2, 3
```

`dfs()` 의 마지막은 제자리로 돌아와야 한다. 제자리로 돌아오는 것은
다음과 같이 구현한다.

```c
robot.turnRight()
robot.turnRight()
robot.move()
robot.turnRight()
robot.turnRight()
```

# Implementation

* [c++11](a.cpp)
* [java8](Solution.java)

# Complexity

```
O(HW) O(HW)
```
