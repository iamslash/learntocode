# Problem

[Coin Change @ leetcode](https://leetcode.com/problems/coin-change/description/)

# Backtracking

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

* [c++11](backtracking.cpp)

## Time Complexity

```
O(N^2) O(1)
```

# Iterative Dynamic Programming

## Idea

`vector<int> C(amount + 1, MAX_VAL)` 를 선언하여 `C[a]` 에 금액의 합이
`a` 인 경우 최소 동전의 개수를 저장한다. 그렇다면 다음과 같은 dynamic
programming equation 을 발견할 수 있다.

```
C[a] = min(C[a], C[a - coins[i]] + 1)
```

모든 반복을 마치고 `C[amount] >= MAX_VAL` 이면
-1 이 답이다. 그렇지 않으면 `C[amount]` 가 답이다.

## Implementation

* [c++11](iterative.cpp)

## Time Complexity

```
O(AC) O(C)
```
