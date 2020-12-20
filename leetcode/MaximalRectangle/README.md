# Problem

* [Maximal Rectangle](https://leetcode.com/problems/maximal-rectangle/)

`0, 1` 로 구성된 이차원 배열 `M[][]` 가 주어진다. 연속된 `1` 로 구성된
사각형중 넓이가 가장 큰 것의 넓이를 구하라.

# Idea

예를 들어서 다음과 같은 행렬 `M` 의 경우를 살펴보자.

```
   0 0 0 1 0 0 0 
   0 0 1 1 1 0 0 
   0 1 1 1 1 1 0

-> 0 0 0 1 0 0 0 height: 0 0 0 1 0 0 0 
   0 0 1 1 1 0 0   left: 0 0 0 3 0 0 0 
   0 1 1 1 1 1 0  right: 7 7 7 4 7 7 7

   0 0 0 1 0 0 0 height: 0 0 1 2 1 0 0
-> 0 0 1 1 1 0 0   left: 0 0 2 3 2 0 0
   0 1 1 1 1 1 0  right: 7 7 5 4 5 7 7

   0 0 0 1 0 0 0 height: 0 1 2 3 2 1 0 
   0 0 1 1 1 0 0   left: 0 1 2 3 2 1 0
-> 0 1 1 1 1 1 0  right: 7 6 5 4 5 6 7
```

언급한 예를 참고하여 다음과 같이 풀어보자.

인덱스 `y, x` 를 이용하여 `M[][]` 을 순회한다. `M[y][x]` 에서 최대의
넓이를 계산할 수 있는 연속된 1 의 높이를 `height[x]` 에
저장한다. 그리고 `height[x]` 를 기준으로 만들 수 있는 최대 사각형의
왼쪽 경계 인덱스를 `left[x]` 에, 오른쪽 경계 인덱스를 `right[x]` 에
저장한다. 넓이는 `(right[x] - left[x]) * height[x]` 를 이용하여
계산한다.

인덱스 `y` 를 `[0..h)` 동안 순회하면서 다음을 반복한다.
* `int curRight = w` 를 선언한다. 인덱스 `x` 를 `(w..0]` 동안
  순회하면서 `right[x]` 를 채운다.
  * `M[y][x] == 1` 이면 `right[x] = min(right[x], curRight)` 를
    수행한다.
  * `M[y][x] != 1` 이면 `right[x] = w, curRight = x` 를 수행한다.
* `int curLeft = 0` 를 선언한다. 인덱스 `x` 를 `[0..w)` 동안
  순회하면서 `left[x], height[x]` 를 채운다.
  * `M[y][x] == 1` 이면 `height[x]++, left[x] = max(left[x], curLeft)`
    를 수행한다.
  * `M[y][x] != 1` 이면 `height[x] = 0, left[x] - 0, curLeft = x + 1`
    를 수행한다.
  * 최대 넓이를 `ans` 를 업데이트한다. 즉, `ans = max(ans,
    (right[i]-left[i])*height[i])` 를 수행한다.

모든 반복을 마치면 `ans` 가 곧 답이다.

# Implementation

* [c++11](a.cpp)
* [java8](Solution.java)

# Complexity

```
O(HW) O(W)
```
