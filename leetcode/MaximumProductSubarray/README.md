# Problem

[Maximum Product Subarray](https://leetcode.com/problems/maximum-product-subarray/)

수열 `A[]` 가 주어진다. 부분수열들 중 원소들의 곱이 최대인 것을
구하라.

# Idea

`int lastMin = A[0]` 을 선언한다. 현재 숫자의 이전 숫자까지 부분수열들
중 원소들의 곱이 최소인 것을 저장한다. 만약 현재 숫자가 음수이고 그
수에 `lastMin` 을 곱하면 부분수열들 중 원소들의 곱이 최대인 것이 된다.

`int lastMax = A[0]` 을 선언한다. 현재 숫자의 이전 숫자까지 부분수열들
중 원소들의 곱이 최대인 것을 저장한다. 모든 반복을 마치면 `lastMax` 가
곧 답이된다.

`int ans = A[0]` 를 선언하여 답을 저장한다.

인덱스 `i` 를 활용하여 `A[]` 를 순회하며 다음을 반복한다.

* `A[i-1]` 이 0 인 경우를 생각해 보아야 한다. 따라서 `A[i]` 만을
  포함한 경우와 `A[i]` 까지 포함한 경우를 생각해 봐야 한다. 부분수열의 곱을
  따져봐야 하기 때문에 `A[i]` 를 포함하지 않는 경우는 생각할 필요가 없다.
* `int tMin` 을 선언하여 `A[i]` 를 포함하고 최소인 경우를
  저장한다. 즉, `tMin = min(lastMin * A[i], lastMax * A[i])` 를
  수행한다.
* `int tMax` 을 선언하여 `A[i]` 를 포함하고 최대인 경우를
  저장한다. 즉, `tMax = max(lastMin * A[i], lastMax * A[i])` 를
  수행한다.
* `lastMin = min(A[i], tMin)` 를 수행한다.
* `lastMax = max(A[i], tMax)` 를 수행한다.
* `ans = max(ans, lastMax)` 를 수행한다.

모든 반복을 마치면 `ans` 가 답이된다.

# Implementation

* [c++11](a.cpp)
* [java8](Solution.java)
* [py3](a.py)

# Complexity

```
O(N) O(1)
```
