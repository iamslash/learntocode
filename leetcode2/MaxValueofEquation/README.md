# Problem

[Max Value of Equation](https://leetcode.com/problems/max-value-of-equation/)

점의 모음 `P[][]`, 숫자 `k` 가 주어진다. 각 점은 `(P[i][0], P[i][1])`
으로 표기하고 `P[][]` 는 `x` 의 오름차순으로 정렬되어 있다. `|x_i -
x_j| <= k (1 <= i < j <= N)` 를 만족하는 점들 중 `y_i + y_j + |x_i -
x_j| (1 <= i < j <= N)` 의 최대인 짝을 찾고 그 최대값을 구하는
문제이다.


# Idea

`P[][]` 는 `x` 의 오름차순으로 정렬되어 있기 때문에 다음의 수식이
성립한다.

```
y_i + y_j + |x_i - x_j| = y_i + y_j + x_j - x_i
                        = y_i - x_i + y_j + x_j
```

`deque<int> D` 를 선언하여 `y - x` 의 값이 내림차순이 되도록
인덱스를 저장한다. 인덱스 `j` 를 선언하여 `P` 를 처음부터 끝까지
순회하면서 다음을 반복한다. 인덱스 `i` 는 `D.front()` 를 의미한다. `l`
은 `D.back()` 를 의미한다.

* `x_j - x_i > k` 인 점을 `D` 에서 모두 제거한다.
* `ans = max(ans, y_i - x_i + y_j + x_j)` 를 수행한다.
  * `D` 는 내림차순으로 정렬되어 있기 때문에 `D` 의 모든 점과 equation
    을 수행할 필요가 없다. D.front() 는 `y - x` 가 가장 큰 점의
    인덱스이기 때문이다.
* `y_l - x_l < y_j - x_j` 인 점을 `D` 에서 모두 제거하여 `D` 를
 `y - x` 의 내림차순으로 정렬한다.

모든 반복을 마치면 `ans` 가 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
