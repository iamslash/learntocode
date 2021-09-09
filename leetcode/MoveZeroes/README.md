# Problem

[Move Zeroes](https://leetcode.com/problems/move-zeroes/)

Given an array `A[]`, Move all 0 to the end of `A[]` while maintaining
the ralative order of the non-zero elements.

# Idea

Move non-zero elements A[j] to A[i] and fill zero at A[i..n).

For example, `A = [0, 1, 0, 3, 12]`.

```
   i               i             i               i
A: 0 1 0 3 12     1 1  0 3 12    1 1  0 3 12    1 3 0 3 12
   j               j               j               j

          i              i                 i               i
A: 1 3 12 3 12    1 3 12 3 12    1 3 12 0 12    1 3 12 0 0
             j                j              j             j
             
```

# Implementation

* [go](a.go)
* [java8](MainApp.java)

# Complexity

```
O(N) O(1)
```
