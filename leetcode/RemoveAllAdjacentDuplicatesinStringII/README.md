# Problem

[Remove All Adjacent Duplicates in String II](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/)

# Idea

Given a string "s" and a integer "k", Remove All
adjacent duplicates in "s".

Use two pointers strategy with one stack.

For Example, s = "abcd", k = 2

```
   k: 2
stck:            1          1 1        1 2        1
      i          i            i            i          i
   s: a b b d    a b b d    a b b d    a b b d    a b b d
      j          j            j            j      j

stck: 1 1         
            i    
   s: a d b d    
        j       
```

# Implementation

* [go](a.go)

# Complexity

```
O(N) O(N)
```
