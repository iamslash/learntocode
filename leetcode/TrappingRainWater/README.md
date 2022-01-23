# Problem

* [Trapping Rain Water
 @ leetcode](https://leetcode.com/explore/interview/card/top-interview-questions-hard/124/others/875/)

# Idea

다음과 같은 변수들을 선언하여 알고리즘을 구상해 보자.

* `int l` : 왼쪽에서 시작하는 인덱스
* `int r` : 오른쪽에서 시작하는 인덱스
* `int lMax` : `height[i]` 의 최대값
* `int rMax`: `height[j]` 의 최대값
* `int ans` : 담을 수 있는 모든 물의 값

예를 들어 `height = [0,1,0,2,1,0,1,3,2,1,2,1]` 의 경우를 살펴보자.

```
       i          
       3
   2    2 2 
 1  1 1  1 1
0 0  0 
       j
  lMax: 3
  rMax: 3
   ans: 6
```

따라서 답은 `6` 이다.

지금까지 만난 높이보다 작은 높이를 만나고 그것 보다 큰 높이를 만나야
웅덩이가 생긴다. 그리고 물을 담을 수 있다.

[two pointers](/doc/two_pointers.md) 로 해결할 만 하다.

인덱스 `l, r` 를 각각 왼쪽 혹은 오른쪽에서 한 칸씩 전진한다. 각각 최대
높이를 기억한다. 최대 높이와 현재 높이의 차이를 답에 더한다. 최대
높이와 현재 높이의 차이를 더하는 방식을 쓰기 때문에 `l, r` 중 더
작거나 같은 높이의 인덱스를 움직여야 한다.

# Implementation

* [c++11](a.cpp)
* [java8](MainApp.java)

# Complexity

```
O(N), O(1)
```
