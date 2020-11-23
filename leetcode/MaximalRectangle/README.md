# Problem

* [Maximal Rectangle](https://leetcode.com/problems/maximal-rectangle/)

# Idea

예를 들어서 다음과 같은 행렬 `M` 이 주어졌다고 해보자. 인덱스 `y, x`
를 이용하여 순회한다. `M[y][x]` 에서 최대의 넓이를 계산할 수 있는
연속된 1 의 높이를 `height[x]` 에, 왼쪽 경계 인덱스를 `left[x]` 에,
오른쪽 경계 인덱스를 `right[x]` 에 저장한다. 한가지 유의사항은 `right`
의 경우 오른쪽에서 왼쪽으로 저장한다. `(right[x] - left[x]) *
height[x]` 를 이용하여 최고 넓이를 갱신한다.

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
