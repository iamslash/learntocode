# Problem

[Longest Palindrome](https://leetcode.com/problems/longest-palindrome/)

# Idea

Given a string "s" which consists of lowercase or uppercase letters, find
the length of the longest palindromes that can be built with those
letters.

for example

```
   in: "abccccdd"
  out: 7
cause: "ccdadcc"

   in: "ccc"
  out: 3
cause: "ccc"

   in: "cccddd"
  out: 5
cause: "cdcdc"
```

Count each character appears in odd and save it to "odds". Then subtract 1 from "odds" if "odds" is greater than 1. Finally subtract "odds" from the length of "s".

# Implementation

* [go](a.go)

# Complexity

```
O(1) O(1)
```
