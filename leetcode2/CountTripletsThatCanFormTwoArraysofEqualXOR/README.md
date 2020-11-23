# Problem

[Count Triplets That Can Form Two Arrays of Equal XOR](https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/)

Given an array of integers `A[]`.
Find the number of triplets i, j, k (0 <= i < j <= k < A.length) where a == b.
Let's define a and b as follows:
* a = A[i] ^ A[i + 1] ^ ... ^ A[j - 1]
* b = A[j] ^ A[j + 1] ^ ... ^ A[k]

# Idea

For all `i` and `k`, where `A[i] ^ A[i + 1] ^ ... ^ A[k] = 0`, then any `j (i
< j <= k)` is ok.

`a == b` means `A[i] ^ A[i + 1] ^ ... ^ A[k] = 0`.

# Implementation

* [java8](Solution.java)

# Complexity

```
O(N^2) O(1)
```
