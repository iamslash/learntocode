# Problem

[Maximum Height by Stacking Cuboids](https://leetcode.com/problems/maximum-height-by-stacking-cuboids/)

상자의 넓이, 길이, 높이의 모음 `A[]` 가 주어진다.  상자를 쌓아올려
보자. 가장 높은 높이를 구하라.

# Idea

상자는 옆으로 뉘일 수도 있고 세울수도 있다.  `A[]` 를 순회하면서
오름차순으로 정리한다. `A[i]` 와 `A[j]` 와 같이 두개의 상자가 있다고
해보자. `A[i][0] <= A[j][0] && A[i][1] <= A[j][1] && A[i][2] <=
A[j][2]` 인 경우 `i` 상자를 `j` 상자위에 올릴 수 있다.

`A.push_back({0, 0, 0})` 를 수행하여 기본값을 삽입한다. 그리고
오름차순으로 정렬한다.

`vector<int> C(n)` 를 선언하여 `C[i]` 에 `i` 개의 상자를 쌓았을 때
최고 높이를 저장한다.

인덱스 `j` 를 `[1..n)` 동안 순회하면서 다음을 반복한다.

* 인덱스 `i` 를 `[0..j)` 동안 순회하면서 다음을 반복한다.
  * `A[i][0] <= A[j][0] && A[i][1] <= A[j][1] && A[i][2] <= A[j][2]` 이면 
    * `A[j]` 를 선택하지 않았을 경우와 선택했을 경우를 비교하여
      최대높이를 `C[j]` 에 저장한다. 즉, `C[j] = max(C[j], C[i] +
      A[j][2])` 를 수행한다.
    * `ans = max(ans, C[j])` 를 수행한다.

모든 반복을 마치면 `ans` 가 곧 답이다.

# Implementation

* [c++11](a.cpp)
* [java8](Solution.java)
* [py3](a.py)

# Complexity

```
O(N^2) O(N^2)
```
