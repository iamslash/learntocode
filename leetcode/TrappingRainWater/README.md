# Problem

* [Trapping Rain Water
 @ leetcode](https://leetcode.com/explore/interview/card/top-interview-questions-hard/124/others/875/)

# Idea

다음과 같은 변수들을 선언하여 알고리즘을 구상해 보자.

* `int i` : 시작하는 인덱스
* `int locMax` : 지금까지 발견한 최고높이 값
* `int maxIdx` : 가장 최고 높이의 인덱스 값
* `int ans` : 담을 수 있는 모든 물의 값

예를 들어 `height = [1,0,2]` 의 경우를 살펴보자. 인덱스 `i` 를 이용해 최고 높이 `maxIdx` 까지 순회한다.   

```
            i
height: 1 0 2
locMax: 1 1 2
   ans: 0 1 1
```

따라서 답은 `1` 이다.

`maxIdx` 를 향해 `locMax` 값을 이용하여 물의 양을 답에 더했다. `maxIdx` 를 찾고 왼쪽 그리고 오른쪽으로 부터 순회한다면 답을 구할 수 있다. 

한편, [two pointers](/doc/two_pointers.md) 를 이용하면 Loop Invariant 를 더욱 간단히 구현할 수 있다.

다음과 같은 변수들을 선언하여 알고리즘을 구상해 보자.

* `int l` : 왼쪽에서 시작하는 인덱스
* `int r` : 오른쪽에서 시작하는 인덱스
* `int lMax` : `height[i]` 의 최대값
* `int rMax`: `height[j]` 의 최대값
* `int ans` : 담을 수 있는 모든 물의 값

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
