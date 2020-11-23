# Problem

[Leftmost Column with at Least a One](https://leetcode.com/problems/leftmost-column-with-at-least-a-one/)

Given 2D array `BinaryMatrix &bm` which is consisted just `0` or
`1`. And each row is sorted by non-decreasing order. Find the left
most column which starts 1. You should not call `bm.get` more than
1000.

# Idea

Traverse from (0, w-1) and loop like this.

* bm.get(y, x) == 1, x--
* bm.get(y, x) == 0, y++

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(HW) O(1)
```
