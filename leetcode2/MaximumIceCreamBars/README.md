# Problem

> [Maximum Ice Cream Bars](https://leetcode.com/problems/maximum-ice-cream-bars/)

수열 `costs[]`, 숫자 `coins` 가 주어진다. `costs[i]` 는 i-th
아이스크림의 가격을 의미한다. `coins` 만큼 동전이 주어졌을 때 가장
많은 수의 아이스크림을 구입할 수 있도록 해보자. 그 때의 아이스크림의
개수를 구하라.

# sort

## Idea

`costs[]` 를 오름차순으로 정렬한다. 처음부터 순회하면서 `coins` 를
넘지않도록 아이스크림을 구매해 본다.

## Implementation

* [java8](MainApp.java)

## Complexity

```
O(NlgN) O(1)
```

# hash map

## Idea

`int maxCost` 를 선언하여 가장 비싼 아이스크림의 가격을 저장한다.
`int[] coinCnts` 를 선언하여 아이스크림의 가격별 개수를 저장한다.
`int ans = 0` 를 선언하여 답을 저장한다.

`int cost = 1` 를 선언하여 `coins >= cost && cost <= maxCost` 동안
`cost` 를 증가하며 다음을 반복한다. 

* `int qty` 를 선언하여 `coinCnts[cost]` 와 `coins/cost` 의 최소값을
  저장한다.
* `cost` 를 `qty` 만큼 구입할 수 있다는 의미이다. 즉, `ans += qty` 를
  수행한다.
* 구입한 만큼 `coins` 에서 제거한다. 즉, `coins -= qty * cost` 를
  수행한다.

모든 반복을 마치면 `ans` 가 답이다.

## Implementation

* [java8](MainApp.java)

## Complexity

```
O(N) O(N)
```
