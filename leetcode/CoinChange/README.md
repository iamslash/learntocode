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

숫자 `amount`, 배열 `coins[]` 가 주어진다. `amount` 금액에 맞는 동전을 선택해
보자. 동전의 최소 개수를 구하라.

# Recursive Dynamic Programming

## Idea

`coins` 를 정렬하고 금액이 큰 동전부터 최대한 많이 사용하는 식으로 dfs
with pruning 전략을 사용해 보자.

다음과 같이 부분문제 `dfs` 를 정의한다.

```
dfs(tgt, idx, cnt)

tgt: 바꾸어야할 금액
idx: index of coins
cnt: 지금까지 사용된 동전의 수
```

`dfs` 는 다음과 같이 base condition 을 처리한다.

* idx 가 0 보다 작으면 리턴한다.
* `coins[idx]` 를 여러개 사용했을 때 tgt 를 교환가능하다면 더이상
  탐색을 진행할 필요가 없다.
* `coins[idx]` 를 최대한 사용한 것과 cnt 의 합이 지금까지 구한 BEST
  보다 같거나 많다면 더이상 탐색을 진행할 필요가 없다.

`dfs` 는 다음과 같이 recursion 을 처리한다.

`i` 를 사용된 동전의 개수라고 해보자. `coins[idx]` 를 최대한 사용한
개수를 `ccnt` 라고 하자. `i` 를 `ccnt` 부터 `0` 까지 순회하면서 다음을
재귀호출하자.

```
dfs(tgt - i * coins[idx], idx - 1, cnt + i)
```

## Implementation

* [c++11](recursive.cpp)

## Time Complexity

```
O(N^2) O(1)
```

# Iterative Dynamic Programming

## Idea

캐시 `int[] C = new int[amount + 1]` 를 선언한다. `C[a]` 에 금액이 `a`
일 때 최소 동전의 수를 저장한다. `C[]` 를 모두 채우면 `C[amount]` 가
답이다. `C[]` 는 `amount + 1` 로 초기화 한다. 동전의 개수는 `amount +
1` 를 넘을 수는 없기 때문이다. 그리고 `C[0] = 0` 으로 초기화 한다.

인덱스 `a` 를 `[0..amount]` 동안 순회하며 다음을 반복한다.
* 인덱스 `i` 를 이용하여 `[0..n]` 동안 순회하며 다음을 반복한다.
  * `coins[i] <= a` 이면 동전 `i` 를 선택할 수 있다는 말이다. 동전
    `i` 가 포함된 경우와 포함되지 않은 경우 금액의 합이 최대인 것을
    `C[a]` 에 저장한다. 즉, `C[a] = min(C[a], 1 + C[a - coins[i]])`

## Implementation

* [c++11](a.cpp)
* [java17](MainApp.java)

## Time Complexity

```
O(AN) O(N)
A: amount
N: number of coins
```
