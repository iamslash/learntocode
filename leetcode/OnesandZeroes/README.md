# Problem

[Ones and Zeroes](https://leetcode.com/problems/ones-and-zeroes/)

# Idea

`0, 1` 로 이루어진 문자열의 모음 `V[]` 와 숫자 `m, n` 이 주어진다.
`m` 개수의 `0` 과 `n` 개수의 `1` 을 이용하여 표현할 수 있는 `V[i]` 의
개수를 구하는 문제이다.

`V[]` 를 처음부터 끝까지 순회한다. `V[i]` 의 `0` 의 개수를 `cnt0`, `1`
의 개수를 `cnt1` 이라고 하자. 이것은 `m - cnt0` 개수의 `0` 과 `n -
cnt1` 개수의 `1` 로 표현할 수 있는 최대 개수에 하나를 더한 것과 같다.
이전에 구한 것을 이용해서 새로운 것을 구할 수 있으니 dynamic
programming 이라고 할만 하다.

캐시 `C[][]` 를 선언한다. `C[i][j]` 는 `i` 개수의 `0` 과 `j` 개수의
`1` 로 표현가능한 최대 개수를 의미한다. 따라서 `C[i][j]` 는 다음과
같이 구현한다.

```cpp
C[i][j] = max(C[i][j], C[i - cnt0][j - cnt1])
```

`V[]` 를 순회하여 `C[][]` 를 모두 채웠다면 `C[m][n]` 이 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(NMN) O(MN)
```
