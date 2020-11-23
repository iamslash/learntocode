# Problem

[Race Car](https://leetcode.com/problems/race-car/)

숫자 `target` 이 주어진다. `0` 에서 출발하여 다음 규칙을 지키면서
`target` 에 도착하기 위한 최소 횟수를 구하라.

* `A` 를 선택하면 `position += speed, speed *= 2`
* `R` 을 선택하면 
  * `speed > 0` 일 때 `position = position, speed = -1`
  * `speed <= 0` 일 때 `position = position, speed = 1`

# Idea

shortest path problem 이다.

item `{step, pos, speed}` 를 선언하여 BFS 로 해결할 만 하다.

```
// target: 5
//     step: 0 1 2 3 4 5 6 7
// position: 0 1 3 3 2 2 3 5
//    speed: 1 2 4-1-2 1 2 4
//           A A R A R A A
```

dynamic programming 으로 최적화할 수 있다. 어렵다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
