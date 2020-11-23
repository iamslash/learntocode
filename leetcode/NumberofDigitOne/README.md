# Problem

[Number of Digit One](https://leetcode.com/problems/number-of-digit-one/)

# Idea

Given an integer n, count the total number of digit 1 appearing in all
non-negative integers less than or equal to n.

For Exapmle, Given n "13", Just do followings.

```
1 2 3 4 5 6 7 8 9    = 1
10 11 12 13          = 4
```

Let's define function f(n) like this.

```
f(9)    = count of 1 [0..9]
        = 1 
f(99)   = count of 1 [0..9] * 10 + count of 1 in [10..19]
        =   f(9) * 10 + 10 
f(999)  =  f(99) * 10 + count of 1 in [100..199] 
        =  f(99) * 10 + 100
f(9999) = f(999) * 10 + 1000
```

Let's think about 23

```
   23 = [0..9] + [10..19] + [20..23]
   
f(23) = f(9) * 2 + 10 + f(3) 
```

Let's think about 2356

```
   2356 = [0..1999] + [2000..2356]
   
f(2356) += (2356 / 1000) * f(1000 - 1) = 2 * f(9999)
        += (2356 / 1000 == 1 ? 356 + 1 : 0)
        += (2356 / 1000  > 1 ? 1000 : 0)
        += f(356)
        
f(2356) = f(999) * 2 + 1000 + f(356)
```

Let's think about 1356

```
   1356 = [0..999] + [1000..2356]

f(1356) = f(999) * 1 + 356 + 1 + f(356)
```

# Implementation

* [go](a.go)

# Complexity

```
O(N) O(N)
```
