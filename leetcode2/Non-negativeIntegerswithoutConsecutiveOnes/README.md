# Problem

[Non-negative Integers without Consecutive Ones](https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/)

숫자 `N` 이 주어진다. `[0..N]` 을 이진수로 표현했을 때 연속된 1 이
없는 숫자의 개수를 구하라.

# References

* [Count number of binary strings without consecutive 1’s](https://www.geeksforgeeks.org/count-number-binary-strings-without-consecutive-1s/)
 
# Idea

`a[]` 를 선언하여 `a[i]` 에 길이가 `i` 이고 `0` 으로 끝나면서 연속된 1
이 없는 숫자들의 개수를 저장한다.  `b[]` 를 선언하여 `b[i]` 에 길이가
`i` 이고 `1` 으로 끝나면서 연속된 1 이 없는 숫자들의 개수를 저장한다.

`a[i]` 는 `a[i-1]` 혹은 `b[i-1]` 갯수 이진수들의 오른쪽에 `0` 을
부착한 이진수들의 갯수와 같다. 또한 `b[i]` 는 `a[i-1]` 갯수 이진수들의
오른쪽에 `1` 을 부착한 이진수들의 갯수와 같다.

그렇다면 다음과 같은 dynamic programming equation 을 생각해 낼 수
있다.

```
a[i] = a[i - 1] + b[i - 1]
b[i] = a[i - 1]

a[1] = b[1] = 1
```

예를 들어 `N = 5` 인 경우를 살펴보자.

| n     |  bin | i   | a   | b   |
| ----- | ---: | --- | --- | --- |
| 0     |    0 |     |     |     |
| 1     |    1 | 1   | 1   | 1   |
| 2     |   10 |     |     |     |
| 3     |   11 | 2   | 2   | 1   |
| 4     |  100 |     |     |     |
| **5** |  101 |     |     |     |
| 6     |  110 |     |     |     |
| 7     |  111 | 3   | 3   | 2   |

It's too dificult.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```
