# Problem

[Minimum Operations to Convert Number](https://leetcode.com/problems/minimum-operations-to-convert-number/)

수열 `nums[]`, 숫자 `start, goal` 이 주어진다.  숫자 `x` 를 `start`
에서 출발하여 `goal` 이 되도록 해보자. 연산의 최소 횟수를 구하라.

`nums[i]` 에 대해 다음과 같은 연산을 무한히 할 수 있다.

* `x + nums[i]`
* `x - nums[i]`
* `x ^ nums[i]`

# Idea

예를 들어 `nums = [2,4,12], start = 2, goal = 12` 의 경우를 살펴보자.

```
2 -> 14 -> 12

2 + 12 = 14
14 - 2 = 12
```

따라서 답은 `2` 이다.

간선의 비용이 1 이고 최단거리의 비용을 찾는 문제이다. [bfs](/fundamentals/graph/bfs/README.md) 로 해결할 만 하다.

`boolean visit[] = new boolean[1001]` 을 선언하여 infinite loop 를
해결하자.

`int step = 0` 을 선언하여 bfs path 의 길이를 저장한다. 이때 문제의
조건에 의해 `start != goal` 이다. `bfs` 에 삽입하기 전에 연산의 결과가
`goal` 과 같은 지 비교해 본다면 time complexity 를 개선할 수 있다.

# Implementation

* [java](MainApp.java)

# Complexity

```
O(3^N) O(3^N)
```
