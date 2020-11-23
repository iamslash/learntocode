# Problem

* [Find K Closest Elements](https://leetcode.com/problems/find-k-closest-elements/)

# Idea

수열 `V` 가 주어지면 `X` 와 가까운 `K` 개의 연속된 숫자들을 찾는 문제이다. Binary Search 를 이용해서 `X` 의 인덱스를 알아내고 `K`
개의 그룹을 왼쪽 혹은 오른쪽으로 적절히 움직여서 옳바른 위치를 
찾아낸다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(lg(N-K)) O(1)
```
