# Problem

* [Maximal Rectangle](https://leetcode.com/problems/maximal-rectangle/)

`0, 1` 로 구성된 이차원 배열 `M[][]` 가 주어진다. 연속된 `1` 로 구성된
사각형중 넓이가 가장 큰 것의 넓이를 구하라.

# Idea

예를 들어서 다음과 같은 행렬 `M` 이 주어졌다고 해보자. 인덱스 `y, x`
를 이용하여 순회한다. `M[y][x]` 에서 최대의 넓이를 계산할 수 있는
연속된 1 의 높이를 `height[x]` 에, 왼쪽 경계 인덱스를 `left[x]` 에,
오른쪽 경계 인덱스를 `right[x]` 에 저장한다.

넓이는 `(right[x] - left[x]) * height[x]` 를 이용하여 계산한다.
`height[x]` 를 기준으로 계산할 수 있는 왼쪽 경계 인덱스와 오른쪽 경계
인덱스를 `left[x], right[x]` 에 저장한다고 생각하자.

인덱스 `y` 를 `[0..h)` 동안 순회하면서 다음을 반복한다.
* 인덱스 `i` 를 `(w..0]` 동안 순히화면서 `right[i]` 를 채운다.
* 인덱스 `i` 를 `[0..w)` 동안 순회하면서 `left[i], height[i]` 를 채운다.
  * 그리고 넓이를 계산하여 최대 넓이를 `ans` 에 저장한다. 즉, `ans =
    max(ans, (right[i]-left[i])*height[i])` 를 수행한다.

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

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(HW) O(W)
```
