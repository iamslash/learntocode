- [Problem](#problem)
- [Recursive Dynamic Programming](#recursive-dynamic-programming)
  - [Idea](#idea)
  - [Implementation](#implementation)
  - [Time Complexity](#time-complexity)
- [Iterative Dynamic Programming](#iterative-dynamic-programming)
  - [Idea](#idea-1)
  - [Implementation](#implementation-1)
  - [Time Complexity](#time-complexity-1)

----

# Problem

[Coin Change | leetcode](https://leetcode.com/problems/coin-change/description/)

숫자 `amount`, 배열 `coins[]` 가 주어진다. `amount` 금액에 맞는 동전을 선택해 보자. 동전의 최소 개수를 구하라.

# Recursive Dynamic Programming

## Idea

다음과 같이 부분문제 `dfs()` 를 정의한다.

```
dfs(C, avail)

return: few count of coins for avail amount
     C: C[a] is min coins for a avail amount
 avail: avail amount
```

## Implementation

* [c++11](recursive.cpp)

## Time Complexity

```
O(AN) O(N)
A: amount
N: number of coins
```

# Iterative Dynamic Programming

## Idea

캐시 `int[] C = new int[amount + 1]` 를 선언한다. `C[a]` 에 금액이 `a` 일 때 최소 동전의 수를 저장한다. `C[]` 를 모두 채우면 `C[amount]` 가 답이다. `C[]` 는 `amount + 1` 로 초기화 한다. 동전의 개수는 `amount + 1` 를 넘을 수는 없기 때문이다. 그리고 `C[0] = 0` 으로 초기화 한다.

인덱스 `a` 를 `[0..amount]` 동안 순회하며 다음을 반복한다.
* 인덱스 `i` 를 이용하여 `[0..n]` 동안 순회하며 다음을 반복한다.
  * `coins[i] <= a` 이면 동전 `i` 를 선택할 수 있다는 말이다. 동전 `i` 가 포함된 경우와 포함되지 않은 경우 금액의 합이 최대인 것을 `C[a]` 에 저장한다. 즉, `C[a] = min(C[a], 1 + C[a - coins[i]])`

## Implementation

* [c++11](a.cpp)
* [java17](MainApp.java)

## Time Complexity

```
O(AN) O(N)
A: amount
N: number of coins
```
