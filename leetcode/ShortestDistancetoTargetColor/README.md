# Problem

[Shortest Distance to Target Color](https://leetcode.com/problems/shortest-distance-to-target-color/)

# Idea

색의 모음 `C[]` 와 질의의 모음 `Q[]` 가 주어진다. `Q[i] = {index of C,
color}` 이다. 또한 color 는 `1, 2, 3` 만 존재한다. `Q[]` 를 순회하면서
`Q[i][0]` 에서 가까운 `Q[i][1]` 를 선택하여 배열에 담는 문제이다.

예를 들어 `C = [1, 1, 2, 1, 3, 2, 2, 3, 3], Q = [[1,3], [2,2], [6,1]]` 를
살펴보자.

먼저 색을 기준으로 인덱스들의 모음을 만들어 보자.

```
1: 0 1 3
2: 2 5 6
3: 4 7 8
```

* `Q[0] = [1,3]` 이다. 색 `3` 으로 부터 1 과 가까운 인덱스는 4 이고 거리는 3 이다.
* `Q[1] = [2,2]` 이다. 색 `2` 으로 부터 2 과 가까운 인덱스는 2 이고 거리는 0 이다.
* `Q[2] = [6,1]` 이다. 색 `1` 으로 부터 6 과 가까운 인덱스는 3 이고 거리는 3 이다.

`vector<vector<int>> col2ids` 를 선언하여 `C` 를 순회하면서 `{color :
[index of C]}` 를 저장한다.

`Q[]` 를 순회하면서 color `Q[i][1]` 에서 가까운 `Q[i][0]` 을 찾는다.
`col2ids[Q[i][1]]` 를 binary search 하여 `Q[i][0]` 을 찾을 수 있다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(lgN) O(N)
```
