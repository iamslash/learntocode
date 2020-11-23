# Problem

[Sell Diminishing-Valued Colored Balls](https://leetcode.com/problems/sell-diminishing-valued-colored-balls/)

수열 `I[]`, 숫자 `orders` 가 주어진다. `I[]` 의 숫자들중 가장 큰 것을
`score` 에 더한다. 그리고 가장 큰 것을 하나 감소한다. 이것을 orders 만큼
반복한다. 그리고 `score` 를 리턴하라.

# Idea

예를 들어 `I = [10, 5], orders = 15` 인 경우를 살펴보자.
먼저 `10,9,8,7,6` 을 `score` 에 더해야 한다.

```
10 + 9 + 8 + 7 + 6 = 10 * 11 / 2 - 5 * 6 / 2 
                   = 55 - 15
                   = 40
```

그리고 남겨진 `I = [5, 5], orders = 10` 을 계산해 보자.

```
5 + 4 + 3 + 2 + 1 + 
5 + 4 + 3 + 2 + 1 = 2 * 5 * 6 /2
                  = 30
```

따라서 답은 70 이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(NlgN) O(1)
```
