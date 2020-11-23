# Problem

[Escape a Large Maze](https://leetcode.com/problems/escape-a-large-maze/)

벽의 좌표의 모음 `B[][]`, 출발 좌표 `S[]`, 도착 좌표 `T[]` 가
주어진다. `S[]` 에서 출발하여 `T[]` 까지 도착할 수 있는지 검증하라.

# Idea

`S[]` 가 벽으로 둘러싸여 있거나 `T[]` 가 벽으로 둘러싸여 있다면 false
를 리턴한다.

`S[]` 에서 `B[][]` 의 개수 만큼 `BFS` 반복을 수행한다. `bfs queue` 가
비어있지 않다면 `S[]` 가 벽으로 둘러싸인 것이 아니다.

`T[]` 에서 `B[][]` 의 개수 만큼 `BFS` 반복을 수행한다. `bfs queue` 가
비어있지 않다면 `T[]` 가 벽으로 둘러쌓인 것은 아니다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(B) O(B)
```
