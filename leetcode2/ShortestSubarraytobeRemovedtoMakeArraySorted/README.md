# Problem

[Shortest Subarray to be Removed to Make Array Sorted](https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/)

수열 `A[]` 가 주어진다. non-decreasing 을 만들기 위해 subarray 를
제거해 보자. subarray 의 최소길이를 구하라. subarray 는 하나인 것 같음.

# Idea

```
            l
            i
  A: 1 2 3 10 4 2 3 5
                      j
                r
ans: 3
```

difficult

# Implementation

* [go](a.go)

# Complexity

```
O(N) O(1)
```
