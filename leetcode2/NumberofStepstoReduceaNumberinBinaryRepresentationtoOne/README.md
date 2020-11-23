# Problem

[Number of Steps to Reduce a Number in Binary Representation to One](https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/)

Given a string `s` which is just consisted of `0` or `1`. Return the number of
steps to reduce it to 1 under the following rules.

* If the current number is even, you have to divide it by 2.
* If the current number is odd, you have to add 1 to it.

# Idea

If you use carry `c` and index `i` you can solve it.
Everytime move `i` increase `ans`. In addition to that, If `s[i] + c
== 1`, increase `ans`. If `c` became 1, it is always `1`.
This is a process of `s = "1101"`.

```
                       i        i        i
   s: 1 1 0 1    1 1 0 1    1 1 0 1    1 1 0 1
   c: 0          1          1          1
 ans: 0          2          4          5
```

After itertaions, the answer is `ans + c`.

# Implementation

* [go](a.go)

# Complexity

```
O(N) O(1)
```
