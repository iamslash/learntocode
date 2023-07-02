- [Abstract](#abstract)
- [Unbounded Knapsack Problem](#unbounded-knapsack-problem)
  - [Problem](#problem)
  - [Idea](#idea)
  - [Implementation](#implementation)
  - [Complexity](#complexity)

----

# Abstract

knapsack problem 에 대해 정리한다. 

knapsack problem 은 여러가지 종류가 있다. 각각의 물건을 `0` 개 혹은 `1` 개 담을
수 있는 것을 [0/1 knapsack
problem](/fundamentals/dynamicprog/knapsack01/README.md), 각각의 물건을 쪼개서
담을 수 있는 것을 [fractional knapsack
problem](fundamentals/greedy/knapsackfractional/README.md) 이라고 한다.

# Unbounded Knapsack Problem

## Problem

숫자`capacity` 와 배열 `weights[], values[]` 가 주어진다. 

`capacity` 까지 감당할 수 있는 배낭과 `n` 개의 물건들이 있다. 이제
물건들을 배낭에 담아보자. 단, 물건 `i` 는 `0` 개 이상 담을 수
있다. 무게는 배낭이 감당할 수 있는 최대가 되어야 하고 담겨진 물건들의
가치 합도 최대가 되도록 하자. 최대 가치를 구하라.

## Idea

[동전교환문제](/leetcode/CoinChange/README.md) 와 유사하다.  Iterative
dynamic programming 으로 해결할 만 하다.

캐시 `C[capacity + 1]` 를 선언한다. `C[]` 를 모두 채우면 `C[capacity]`
가 답이다. `C[w]` 는 `w` 개의 물건을 배낭에 담았을 때 최대 가치를
저장한다.

인덱스 `w` 를 `[0..capacity]` 동안 순회하며 다음을 반복한다.
* 인덱스 `i` 를 이용하여 `[0..n]` 동안 순회하며 다음을 반복한다.
  * `weights[i] <= w` 이면 물건 `i` 를 넣을 수 있다는 의미이다. 물건
    `i` 가 포함된 경우와 포함되지 않은 경우 가치의 합이 최대인 것을
    `C[w]` 에 저장한다. 즉, `C[w] = max(C[w], values[i] + C[w -
    weights[i]])`

## Implementation

* [c++11](a.cpp)
* [java11](MainApp.java)

## Complexity

```
O(CN) O(C)

C: capacity
N: the number of packages
```
