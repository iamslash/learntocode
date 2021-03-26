# Problem

> [Campus Bikes](https://leetcode.com/problems/campus-bikes/)

일꾼 좌표의 모임 `W[]`, 자전거 좌표의 모임 `B[]` 가 주어진다.  일꾼과
저전거의 거리를 맨하탄 방법으로 계산하여 가까운 것들 끼리
짝지운다. 일꾼 별로 할당된 자전거 인덱스의 모임을 계산하는 문제이다.
참고로 두점 `a, b` 의 맨하탄 거리는 `|a.x - b.x| + |a.y - b.y|` 이다.

# Idea

먼저 `vector<vector<pair<int, int>>> dist2pairs` 를 만들고 거리별
`{worker index, bike index}` 리스트를 저장한다.

문제의 조건에 의해 `0 <= workers[i][j], bikes[i][j] < 1000` 이기
때문에 `0 <= 맨하탄 거리 < 2000` 이다. 따라서 `dist2pairs.size() <
2000` 이다.

`vector<bool> usedBike` 를 선언하여 일꾼에게 할당된 자전거를 표시하자.
`dist2pairs` 를 `[0, 2000)` 동안 순회한다. 가장 가까운 거리이고 아직
짝지어지지 않은 일꾼과 자전거를 짝지을 수 있다.

# Implementation

* [c++11](a.cpp)
* [java8](MainApp.java)

# Complexity

```
O(WB) O(1)
```
