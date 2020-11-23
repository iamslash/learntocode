# Problem

[Maximum Size Subarray Sum Equals k](https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/)

# Idea

수열 `V` 와 숫자 `k` 가 주어지면 부분 수열들 중 합이 `k`
인 것들 중 가장 길이가 긴 것을 구하는 문제이다.

다음과 같이 `V = (1, -1, 5, -2, 3), k = 3` 일 때
인덱스 i 를 이용하여 처음부터 끝까지 순회하면서 다음을 반복한다.

```
   i
V: 1, -1, 5, -2, 3
k: 3
```

0. `sum` 에 `V[i]` 을 더한다.
1. 맵 `ump` 에 `sum` 이 없다면 `{sum, i}` 를 추가한다.
2. `tgt = sum - k` 를 수행한다. `tgt` 가 `ump` 에 존재한다면 합이 k 인
   부분 수열을 찾은 것이다. 길이 `len = i - ump[tgt]` 가 답의 후보들 중
   하나이다.

# Implementation

* [c++11](a.cpp

# Complexity

```
O(N) O(N)
```
