- [Abstract](#abstract)
- [Fractional Knapsack Problem](#fractional-knapsack-problem)
  - [Problem](#problem)
  - [Idea](#idea)
  - [Implementation](#implementation)
  - [Time Complexity](#time-complexity)

----

# Abstract

knapsack problem 에 대해 적어본다. 

knapsack problem 은 여러가지 종류가 있다. 각각의 물건을 `0` 개 혹은 `1` 개 담을
수 있는 것을 [0/1 knapsack
problem](/fundamentals/dynamicprog/knapsack01/README.md), 각각의 물건을 쪼개서
담을 수 있는 것을 [fractional knapsack
problem](fundamentals/greedy/knapsackfractional/README.md) 이라고 한다.

# Fractional Knapsack Problem

## Problem

특정 무게 `C` 까지 감당할 수 있는 배낭과 `N` 개의 물건들이 있다고 하자. 그리고
물건 각각의 무게를 `W_i`, 가치를 `V_i` 라고 하자. 이제 물건들을 배낭에 담아보자.
단, 물건 `i` 는 `0` 개 이상 담을 수 있다. 그런데 물건을 쪼개서 담을 수도 있다.
예를 들어서 물건 `i` 를 `1/2` 개 담을 수 도 있다. 무게는 배낭이 감당할 수 있는
최대가 되어야 하고 담겨진 물건들의 가치 합 역시 최대가 되도록 물건들을 조합해
보자.

## Idea

`greedy algorithm` 을 이용하여 해결하자.  단위 무게당 가치가 제일 높은 녀석부터
선택하여 배낭에 담는다.

## Implementation

* [c++11](a.cpp)

## Time Complexity

```
O(NlgN) O(1)
```