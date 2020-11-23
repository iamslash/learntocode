# Problem

[Number of 1 Bits](https://leetcode.com/problems/number-of-1-bits/)

# Idea

Takes and unsigned integer and return the number of 1 bits it has.

`bm & bm - 1` shows bm has 1 right most bits.

For example, Let's take a look at `0011 1000`

```
bm     : 0011 1000
bm - 1 : 0011 0111

bm     : 0011 0000
bm - 1 : 0010 1111
     
bm     : 0010 0000
bm - 1 : 0001 1111

bm     : 0000 0000
```

# Implementation

* [go](a.go)

# Complexity

```
O(1) O(1)
```
