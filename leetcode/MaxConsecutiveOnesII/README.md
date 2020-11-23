# Problem

[Max Consecutive Ones II](https://leetcode.com/problems/max-consecutive-ones-ii/)

# Idea

`1, 0` 으로 구성된 수열 `V` 가 주어진다. 하나의 `0` 을 `1` 로 바꿀 수
있다면 연속된 `1` 로 구성된 수열중 가장 긴 것의 길이를 구하는
문제이다.

인덱스 `i` 를 이용하여 `V` 를 처음부터 끝까지 순회하면서 다음을 반복한다.

1. `V[i] == 1` 이면 현재 연속된 1 의 길이를 하나 증갛나다. `cur++`
2. `V[i] == 0` 이면 현재 연속된 1 의 길이를 하나 증가하고 이전 연속된
   1 의 길이에 저장한다. `prv = cur, cur = 0`
3. `cur + prv` 가 최대인 것을 결과값에 저장한다. `rst = max(rst, prv + cur)`

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```
