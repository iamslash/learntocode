# Problem

* [Trapping Rain Water
 @ leetcode](https://leetcode.com/explore/interview/card/top-interview-questions-hard/124/others/875/)

# Idea

다음과 같은 변수들을 선언하여 알고리즘을 구상해 보자.

* `int i` : 왼쪽에서 시작하는 인덱스
* `int j` : 오른쪽에서 시작하는 인덱스
* `int leftMaxHeight` : `height[i]` 의 최대값
* `int rightMaxHeight`: `height[j]` 의 최대값
* `int leftWater` : `height[i]` 의 누적합산 값
* `int rightWater` : `height[j]` 의 누적합산 값
* `int trapWater` : 담을 수 있는 모든 물의 값

예를 들어 `height = [0,1,0,2,1,0,1,3,2,1,2,1]` 의 경우를 살펴보자.

```
       i          
       3
   2    2 2 
 1  1 1  1 1
0 0  0 
       j
  leftHeight: 3
 rightHeight: 2
  leftWater: 4
 rightWater: 0
      water: 2
```

따라서 답은 `5` 이다.

이번에는 `height = [4,2,0,3,2,5]` 의 경우를 살펴보자.

```
     i
     5
4
   3
 2  2

  0
     j
  leftMaxHeight: 4 
 rightMaxHeight: 0
  leftWater: 9
 rightWater: 0
  trapWater: 0
```

따라서 답은 `9` 이다.

[two pointers](/doc/two_pointers.md) 로 해결할 만 하다.

인덱스 `i, j` 를 각각 왼쪽에서 오른쪽에서 한 칸씩 전진한다. 각각 최대
높이를 기억하면서 담겨질만한 물의 높이를 기억한다. 그리고 지금까지
담은 물을 더하는 순간 답에 더한다.

# Implementation

* [c++11](a.cpp)
* [java8](MainApp.java)

# Complexity

```
O(N), O(1)
```
