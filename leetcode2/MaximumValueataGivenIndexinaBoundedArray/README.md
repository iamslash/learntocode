# Problem

> [Maximum Value at a Given Index in a Bounded Array](https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/)

숫자 `n, idx, maxSum` 이 주어진다. `n` 개의 수열 `A[]` 가 있다.
`A[i]` 는 양수이다. `sum(A)` 는 `maxSum` 을 넘지 않도록 `A[]` 를
구성해 보자. 그때 `A[idx]` 의 최대값을 구하라.

# Brute Force

## Idea

예를 들어 `n = 4, idx = 2,  maxSum = 6` 의 경우를 살펴보자.

```
1 1 1 1
maxSum: 6 - 4 = 2

    1
1 1 1 1
maxSum: 2 - 1 = 1
```

따라서 답은 2 이다.

이번에는 `n = 6, idx = 1,  maxSum = 15` 의 경우를 살펴보자.

```
1 1 1 1 1 1
maxSum: 15 - 6 = 9

  1
1 1 1 1 1 1
maxSum:  9 - 1 = 8

  1
1 1 1  
1 1 1 1 1 1
maxSum:  8 - 3 = 5

  1
1 1 1  
1 1 1 1
1 1 1 1 1 1
maxSum:  5 - 4 = 1
```

따라서 답은 4 이다.

## Implementation

* [java8](MainApp.java)

## Complexity

```
O(N) O(1)
```

# Binary Search

## Idea

먼저 다음과 같이 연속된 수열이 있을 때 그 합을 구하는 방법을 알아보자.
이것을 Gauss Summation 이라고 한다???
```
4 5 6 7 8 9
sum = (4+9)*(9-4+1)/2 = 13*3
There are 3 of (4+9).

a a+1 a+2 b
sum = (a+b)*(b-a+1)/2
```

`A[idx]` 를 [binary search right most equal](/fundamentals/search/binarysearch/README.md) 를 이용해서 찾는다. 

`A[idx]` 를 `idxVal` 이라고 하자. `A[idx]` 는 꼭대기 값이다.  왼쪽 끝
값은 `A[0] = max(idxVal - idx, 0` 이다. 오른쪽 끝 값은 `A[n-1] =
max(idxVal - ((n-1)-idx), 0)` 이다.

이제 `A[idx]` 즉 `idxVal` 가 정해지면 `sum(A[0]..A[idx])` 와
`sum(A[idx]..A[n-1]` 를 구할 수 있다. 이때 앞서 살펴봤던 연속된 수열의
합을 이용한다.

## Implementation

* [java8](MainApp.java)

## Complexity

```
O(lgN) O(1)
```
