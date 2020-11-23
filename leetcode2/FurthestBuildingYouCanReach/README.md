# Problem

[Furthest Building You Can Reach](https://leetcode.com/problems/furthest-building-you-can-reach/)

빌딩 높이의 모음 `heights`, 벽돌의 개수 `bricks`, 사다리의 개수
`ladders` 가 주어진다. 0-th 빌딩 부터 오른쪽으로 빌딩들의 옥상으로
이동해 보자. `heights[n+1] - heights[n]` 가 양수이면 높이의 차이 만큼
벽돌을 사용하여 이동할 수 있다. 혹은 사다리 하나를 이용해서 이동할 수
있다. 주어진 `bricks, ladders` 를 이용하여 최대로 멀리가 보자. 그때의
빌딩의 인덱스를 리턴하라.

# Idea

예를 들어 `heights = [1, 3, 5, 7]` 이고 `bricks = 1, ladders =
1`,`bricks = 2, ladders = 1`,`bricks = 1, ladders = 2`, 경우를
살펴보자.

```
           i
      H: 1 3 5 7
 bricks: 1
ladders: 1

             i
      H: 1 3 5 7
 bricks: 2
ladders: 1

             i
      H: 1 3 5 7
 bricks: 1
ladders: 2
```

ladders 는 높이에 관계없이 사용할 수 있다. ladders 가 bricks 보다
가치가 크다. 벽돌로 먼저 시도해보고 지금까지 소모한 벽돌보다 사다리를
사용하는 것이 효율적인지 판단한다.  사다리를 사용하는 것이 더욱
효율적이면 벽돌을 다시 더하고 사다리를 하나 소모한다.

`priority_queue<int> usedBrickPq` 를 선언하여 사용한 벽돌의 개수를
저장하자. 그리고 `heights = [1, 3, 5, 7]` 이고 `bricks = 1, ladders =
1`,`bricks = 2, ladders = 1`,`bricks = 1, ladders = 2`, 경우를 다시
살펴보자.

```
  brick: 
           i
      H: 1 3 5 7
 bricks: 1
ladders: 0
     pq: 

             i
      H: 1 3 5 7
 bricks: 0
ladders: 1
     pq: 2

             i
      H: 1 3 5 7
 bricks: 1
ladders: 0
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(NlgN) O(N)
```
