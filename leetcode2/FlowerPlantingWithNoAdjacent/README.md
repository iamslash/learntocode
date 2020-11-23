# Problem

[Flower Planting With No Adjacent](https://leetcode.com/problems/flower-planting-with-no-adjacent/)

# Idea

화분의 개수 `N`, 화분의 연결의 모음 `P[]` 가 주어진다. `P[i][0]` 과
`P[i][1]` 연결되어 있다. 그리고 화분에 `1, 2, 3, 4` 와 같이 4가지 색의
꽃을 심을 수 있다. 서로 연결된 화분은 서로 다른 색의 꽃을 심도록
배치하는 문제이다.

먼저 `P[]` 를 읽고 graph `G[][]` 를 생성한다. 이때 양방향으로
저장해야함을 유의하자. `int ans[N]` 을 선언하여 `ans[i]` 에 심은 꽃을
저장하자. 기본값은 0 이다.

그리고 화분 `u` 를 방문할 때 마다 다음을 반복한다.  `u` 의 이웃 화분을
`v` 라 하자. `int usedFlowers[5]` 를 선언하여 사용여부를 저장한다.

* `v` 화분에 심은 꽃들을 `usedFlowers[c]` 에 1 로 표기한다.
* `u` 화분에 심을 꽃은 `usedFlowers` 중에 0 인 것을 고른다.

모든 반복을 마치면 `ans` 가 답이다.
 
# Implementation

* [java8](Solution.java)

# Complexity

```
O(N) O(N)
```
