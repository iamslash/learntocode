# Problem

[Maximum Number of Coins You Can Get](https://leetcode.com/problems/maximum-number-of-coins-you-can-get/)

수열 `P[]` 가 주어진다. 3 개씩 쌍을 골라서 중간 값을 취하라.  내가
얻는 값이 최대가 되도록 했을 때 그 값을 구하라.

# Idea

예를 들어, `A = [9, 8, 7, 6, 5, 4, 3, 2, 1]` 의 경우를 살펴보자.

```
9 8 7 6 5 4 3 2 1
. .             .
    . .       .
        . . .
```

오름차순으로 정렬하고 다시 생각해 보자.

```
1 2 3 4 5 6 7 8 9
    . . .
  .       . .
.             . .  
```

# Implementation

* [golang](a.go)

# Complexity

```
O(N) O(1)
```
