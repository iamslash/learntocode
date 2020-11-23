# Problem

[Find a Value of a Mysterious Function Closest to Target](https://leetcode.com/problems/find-a-value-of-a-mysterious-function-closest-to-target/)

수열 `A[]`, 숫자 `tgt` 가 주어진다.  다음과 같은 함수 `func` 를
정의하자.  `|func(A, l, r) - tgt|` 가 최소가 되었을 때 그 값을 구하라.
`0 <= l, r < n` 이다.

# Idea

어떤 수 `a` 를 다른 수 `b` 와 `&` 연산을 수행하면 `a` 보다 작거나 같을
뿐 커지지는 않는다. 이러한 규칙을 활용하여 건너뛰기 방법을 사용해 보자.

먼저 `int ans = INT_MAX` 를 선언하여 `tgt` 와 차이가 최소인 것을
저장한다.

인덱스 `i` 를 이용하여 `[0..n)` 를 순회하며 다음을 반복한다. 

* `int k = A[i]` 를 수행한다.
* 인덱스 `j` 를 이용하여 `[i..n)` 를 순회하며 다음을 반복한다.
  * `k &= A[j]`
  * `int diff = abs(k - tgt)`
  * 이때 `diff > ans` 이면 앞으로 `&` 연산을 계속할 수록 `k` 는 작아질
    테고 `diff` 역시 커질 것이다. loop 를 종료해서 건너뛴다.
  * `ans = diff`
  * `k <= tgt` 이면 앞으로 `&` 연산을 계속할 수록 `k` 는 작아질 테고
    `diff` 역시 커질 것이다. loop 를 종료해서 건너뛴다.
    
모든 반복을 마치면 `ans` 가 곧 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N^2) O(1)
```
