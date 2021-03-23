# Problem

> [Number of Orders in the Backlog](https://leetcode.com/problems/number-of-orders-in-the-backlog/)

주문의 모음 `orders[][]` 가 주어진다. `orders[i][0], orders[i][1],
orders[i][2]` 는 각각 `price_i, amount_i, type_i` 을
의미한다. `type_i` 는 `0` 이면 buy, `1` 이면 `sell` 를 의미한다.

`backlog` 라는 자료구조가 있다. `orders[][]` 를 차례대로
아래와 같은 규칙을 지키면서 `backlog` 에 삽입한다.

> * `type_i == buy` 이면 `backlog` 의 sell 주문들 중 `price_i` 보다
>   작거나 같은 것들을 제거한다. 제거하는 개수는 `amount_i` 보다
>   작거나 같아야 한다.
> * `type_i == sell` 이면 `backlog` 의 buy 주문들 중 `price_i` 보다
>   크거나 같은 것들을 제거한다. 제거하는 개수는 `amount_i` 보다
>   작거나 같아야 한다.

모든 반복을 마친후 `backlog` 에 남겨진 주문들의 amount 합을 구하라.

`amount_i` 의 일부만 제거할 수 있다는 점을 주의하라.

# Idea

예를 들어 `orders = [[10,5,0],[15,2,1],[25,1,1],[30,4,0]]` 의 경우를 살펴보자.

```
      orders: 10 5 0 <
              15 2 1
              25 1 1
              30 4 0
 buy backlog: 10 10 10 10 10
sell backlog: 

      orders: 10 5 0 
              15 2 1 <
              25 1 1
              30 4 0
 buy backlog: 10 10 10 10 10
sell backlog: 15 15

      orders: 10 5 0 
              15 2 1 
              25 1 1 <
              30 4 0
 buy backlog: 10 10 10 10 10
sell backlog: 15 15 25

      orders: 10 5 0 
              15 2 1 
              25 1 1 
              30 4 0 <
 buy backlog: 10 10 10 10 10 30
sell backlog: 
```

따라서 답은 6 이다.

# Implementation

* [java8](Main.java)

# Complexity

```
O(NlgN) O(1)
```
