# Problem

[LIS @ leetcode](https://leetcode.com/problems/longest-increasing-subsequence/description/)

# Iterative Solution

## Idea

수열 `A` 가 주어진다. longest increasing subsequence 의 개수를 구하는
문제이다.

먼저 `vector<int> lis` 를 선언하여 Longest Increasing Subsequence 를
저장한다. 인덱스 `i` 를 이용하여 `A` 를 처음부터 끝까지 순회하며 다음을 반복한다.

* `auto it = lower_bound(lis.begin(), lis.end(), A[i])` 를 수행한다.
  `it` 가 없다면 `lis.push_back(A[i])` 를 수행한다.
* `it` 가 있다면 `*it = A[i]` 를 수행한다. `lis` 에 가능한한 많은 수를
  저장하기 위해서 `*it` 를 가능하면 더욱 낮은 값으로 저장한다.

모든 반복을 마치면 `ans.size()` 가 답이다.
 
## Implementation

* [c++11](a.cpp)

## Complexity

```
O(NlgN) O(1)
```
