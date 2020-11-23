# Problem

[Counting Bits @ leetcode](https://leetcode.com/problems/counting-bits/description/)

# Idea

만약 임의의 이진수 `a` 가 있다고 해보자.  그 녀석을 오른쪽으로 한 비트
이동한 이진수를 `b` 라고 해보자.  `a` 가 소유하고 있는 1 의 개수는 0
index 를 제외하고 `b` 가 소유하고 있는 1 의 개수와 같다.  따라서 `b`
의 1 의 개수와 `a` 의 0 index 의 숫자가 1인지 여부를 더하면 `a` 가
소유하고 있는 1 의 개수를 구할 수 있다. `a` 를 1 부터 시작하면
bottom-up style 로 임의의 숫자에대해 1 의 개수를 구할 수 있다.

```
a = 1101
b = 0110
```

# Implementation

[c++11](a.cpp)

# Time complexity

```
O(N)
```

# Space Complexity

```
O(N)
```
