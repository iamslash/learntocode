# Problem

[Minimum Cost to Connect Sticks](https://leetcode.com/problems/minimum-cost-to-connect-sticks/)

막대기 길이의 모음 `S[]` 가 주어진다. 임의의 두개의 막대기를 고르고
둘의 길이를 각각 `a, b` 라고 하자. 합한 막대기의 길이는 `c` 라 하고
합할 때 비용은 `a + b` 이라고 하자. 막대기가 하나가 남을 때까지 비용이
최소가 되는 방향으로 합한다. 그때 최소의 비용을 구하는 문제이다.

# Idea

예를 들어 `S = [2, 4, 3]` 인 경우를 살펴보자. 

* `2, 3` 을 합하면 비용은 `5` 이다. 이후 `4, 5` 를 합하면 비용은 `9`
이다. 총 비용은 `5 + 9 = 14` 이다.
* `3, 4` 를 합하면 비용은 `7` 이다. 이후 `2, 7` 을 합하면 비용은 `9`
이다. 총 비용은 `7 + 9 = 16` 이다.

greedy approach 로 해결할 만하다. 가장 작은 길이의 막대기 둘을 고르고
합하는 방법을 사용한다. 막대기의 길이를 우선순위큐에 너어두면 항상
작은 길이의 막대기 두개를 고를 수 있다.

# Implementation

* [c++11](a.cpp)
* [java8](MainApp.java)
* [python3](a.py)

# Complexity

```
O(NlgN) O(N)
```
