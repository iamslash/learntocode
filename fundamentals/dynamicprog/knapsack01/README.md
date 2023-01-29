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

[동전교환문제](/leetcode/CoinChange/README.md) 와 유사하다.

특정 무게 `G` 까지 감당할 수 있는 배낭과 `N` 개의 물건들이 있다고 하자. 그리고
각각의 물건 무게를 `W_i`, 가치를 `V_i` 라고 하자. 이제 물건들을 배낭에 담아보자.
단, 물건 `i` 는 `0` 개 이상 담을 수 있다. 무게는 배낭이 감당할 수 있는 최대가
되어야 하고 담겨진 물건들의 가치 합 역시 최대가 되도록 물건들을 조합해 보자.

## Idea

캐시 `C[G + 1]` 를 선언한다. `C[]` 를 모두 채우면 `C[G]` 가 답이다.

인덱스 `a` 를 `[0..G]` 를 순회하며 다음을 반복한다.

* 인덱스 `j` 를 이용하여 `[0..N]` 을 순회하며 다음을 반복한다.
  * `W[j] <= a` 이면 물건 `j` 를 넣을 수 있다는 의미이다. 물건 `j` 가 포함된
    경우와 포함되지 않은 경우 가치의 합이 최대인 것을 `C[a]` 에 저장한다. 즉,
    `C[a] = max(C[a], V[j] + C[a - W[j]])`

## Implementation

* [c++11](a.cpp)

## Complexity

```
O(GN) O(G)
```
