# Problem

Hamming weight is the number of 1's in the string consisted `0, 1`. For example, The hamming weight of `10101` is 3.

[Number of 1 Bits](/leetcode/Numberof1Bits/README.md)

# Idea

Given a string `s` consisted `0, 1`, Do `s = s & (s - 1)` Until `s > 0`. The count of assignment is the Hamming weight.

# Implmentation

[go](/leetcode/Numberof1Bits/a.go)

# Complexity

```
O(1) O(1)
```
