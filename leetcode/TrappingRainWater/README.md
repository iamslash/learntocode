# Problem

* [Trapping Rain Water
 @ leetcode](https://leetcode.com/explore/interview/card/top-interview-questions-hard/124/others/875/)

# Idea

다음과 같은 변수들을 선언하여 알고리즘을 구상해 보자.

* `int i` : 왼쪽에서 시작하는 인덱스
* `int j` : 오른쪽에서 시작하는 인덱스
* `int leftMaxHeight` : `height[i]` 의 최대값
* `int rightMaxHeight`: `height[j]` 의 최대값
* `int trapWater` : 담을 수 있는 모든 물의 값

예를 들어 `height = [0,1,0,2,1,0,1,3,2,1,2,1]` 의 경우를 살펴보자.

```
       i          
       3
   2    2 2 
 1  1 1  1 1
0 0  0 
       j
  leftMaxHeight: 3
 rightMaxHeight: 3
      trapWater: 6
```

따라서 답은 `6` 이다.

[two pointers](/doc/two_pointers.md) 로 해결할 만 하다.

인덱스 `i, j` 를 각각 왼쪽에서 오른쪽에서 한 칸씩 전진한다. 각각 최대
높이를 기억한다. 최대 높이와 현재 높이의 차이를 답에 더한다.

# Implementation

* [c++11](a.cpp)
* [java8](MainApp.java)

# Complexity

```
O(N), O(1)
```
