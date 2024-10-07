# Problem

[Longest Palindromic Subsequence](https://leetcode.com/problems/longest-palindromic-subsequence/)

Given a string `s`. Find the longest palindrome subsequence's length.

# Idea

Let's Define a cache `int C[len][start_idx]` which means the longest palindrome subsequences's length.

* `len`: the length of sub palindrome.
* `start_idx`: the started index of sub palindrome whose length is `len`.

Let's take a look at `s = "bbbab"`.

```
  b b b a b
  0 1 2 3 4
0 0 0 0 0 0 
1 1 1 1 1 1
2 2 2 1 1 
3 3 2 3
4 3 3
5 4
```

Finally the answer is `C[5][0]`.

We can find a rule like this.

```
if leftmost character is same with rightmost character.
  C[len][idx] = C[len-2][idx+1] + 2 or
unless
  C[len][idx] = max(C[len-1][idx], C[len-1][idx+1])
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N^2) O(N^2)
```
