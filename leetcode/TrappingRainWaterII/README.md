# Problem

* [Trapping Rain Water II](https://leetcode.com/problems/trapping-rain-water-ii/)

# Idea

높이정보를 담은 이차원 배열 `G` 가 주어진다.  비가 왔을 때 담길 수
있는 물의 부피를 구하는 문제이다.

priority queue `pq` 를 생성한다. 가장 자리는 물이 담기지 못한다. 가장
자리의 높이들을 `pq` 에 삽입한다.

1. 가장 작은 높이의 노드 `u` 를 `pq.top; pq.pop` 을 통해 얻어온다.
2. `u` 의 방문하지 않은 이웃들을 `pq.push` 한다. 만약 그 이웃들 중 `u` 보다 작은 높이의 이웃 `v`
   가 있다면 `u.height - v.height` 만큼 물이 채워질 것이다.
3. `1, 2` 를 반복한다.

다음은 `3X3` 크기의 `G` 에 대해서 채워진 물의 부피를 구하는 과정이다.

```
① ② ③ ④ ⑤
❶ ❷ ❸ ❹ ❺

h:0      h:0      h:1
1 4 3    ❶ ④ ③    ❶ ④ ③
3 1 2    ③ 1 ②    ③ ① ❷
2 3 3    ② ③ ③    ② ③ ③
```

# Implementation

* [c++](a.cpp)

# Complexity

```
O(NlgN) O(N)
```
