# Problem

[Closest Dessert Cost](https://leetcode.com/problems/closest-dessert-cost/)

수열 `baseCosts[], toppingCosts[]`, 숫자 `target` 이 주어진다.
`baseCosts[i]` 는 `i-th` 아이스크림의 비용이다. `toppingCosts[j]` 는
`j-th` 토핑의 비용이다. 다음과 같은 규칙을 지키면서 아이스크림위에 토핑을
얹혀 보자.

> * 하나의 아이스크림만 사용한다.
> * 하나의 아이스크림위에 토핑을 여러개 올릴 수 있다. 올리지 않을 수도
>   있다.
> * 한가지 토핑은 최대 2 개까지 사용가능하다.

비용의 합이 target 에 가까운 값을 구하라. 가까운 값이 2 개이면 작은
것을 선택하라.

# Idea

예를 들어 `baseCosts = [1,7], toppingCosts = [3,4], target = 10` 의
경우를 살펴보자.

```
   base cost: 7

topping cost: 3 * 1

        best: 7 + 3 = 10
```

따라서 답은 `10` 이다.

토핑의 개수가 최대 2 개이다. 한가지 토핑에 대해 0, 1, 2 개가 더해졌을 때를
고려하면 된다. 문제의 조건에 의해 `baseCosts[], toppingCosts[]` 의 크기가 작다.
완전탐색으로 해결할 만 하다. 특히 [back tracking]() 으로 해결해 보자.

다음과 같은 부분문제를 정의한다.

```
void dfs(toppingCosts, target, best, cost, i)

toppingCosts: input toppingCosts
      target: input target
        best: best cost
        cost: current cost
           i: i-th icecream
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(?) O(?)
```
