# Problem

[Maximum Subarray Sum with One Deletion](https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/)

# Idea

수열의 모음 `A[]` 가 주어진다. subarray 를 하나 고르고 원소중 하나를
지웠을 때 그 합이 최대가 되도록 해보자. 그 합을 구하는 문제이다.

임의의 `A[i]` 를 선택했을 때 `A[0..i-1]` 의 subarray 중 합이 최대인
것과 `A[i+1..n-1]` 의 subarray 중 합이 최대인 것을 골라서 그 합을
구하면 곧 답이다.

`vector<int> F(n)` 를 선언하여 `A[0]` 부터 subarray 의 최대 합을
저장한다. `F[i-1]` 는 `A[0..i-1]` 의 subarray 중 최대합이 저장되어
있다.

`vector<int> B(n)` 을 선언하여 `A[n-1]` 부터 subarray 의 최대 합을
저장한다. `B[i+1]` 는 `A[i+1..n-1]` 의 subarray 중 최대합이 저장되어
있다.

`int ans` 를 선언하고 인덱스 `i` 를 `[1..n-2]` 동안 순회하면서 다음을
반복한다.

* `ans = max(ans, F[i-1]+B[i+1])`

모든 반복을 마치면 `ans` 가 곧 답이다.
 
# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
