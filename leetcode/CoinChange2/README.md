# Problem

* [Coin Change 2 | leetcode](https://leetcode.com/problems/coin-change-2/)

코인들의 배열 `coins` 을 사용하여 총액 `amount` 를 만들어내는 가짓수를 구하는 문제이다.

# Idea

dynamic programming 전략을 위해 다음과 같이 캐시 `C` 를 정의하고 `C[0] = 1` 로 초기화 하자.

```
C[amount+1]

C[i] : count of i amount
```

선택한 코인을 `c` 라고 하고 `i` 를 `[0, amount]` 영역의 인덱스라고 하면 다음과 같은 중요한 규칙을 발견할 수 있다.

```
C[i+c] += C[i]
```

모든 코인에 대해 모든 총액에 대해 순회하면서 위의 규칙을 적용한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N^2) O(N)
```
