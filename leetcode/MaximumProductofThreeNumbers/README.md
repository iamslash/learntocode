# Problem

[Maximum Product of Three Numbers](https://leetcode.com/problems/maximum-product-of-three-numbers/)

# Idea

원소의 개수가 3 개 이상인 수열 `A` 가 주어진다. 3 개의 숫자를 골라서
모두 곱해 보자.  그 곱의 크기가 가장 클 때 그 값을 구하라.

일단 정렬하고 가장 큰 값 부터 3 개를 골라서 곱하면 될 것 같다. 그러나
음수를 고려해야 하기 때문에 그렇지 않다.

가장 큰 값 부터 3 개를 `max1, max2, max3` 에 저장한다.  음수도
고려해야 하기 때문에 가장 작은 값부터 2 개를 `min1, min2` 에 저장한다.

다음과 같이 `max1, max2, max3, min2, min1` 의 부호들의 경우의 수를
생각해 볼 수 있다. 1, 2, 3, 5, 6 의 경우는 `max1*max2*max3` 가
최대값이다. 4 의 경우는 `max1*min2*min1` 이 최대값이다.

```
      1 2 3 4 5 6
max1: + + + + + -
max2: + + + + - -
max3: + + + - - -
...
min2: + + - - - -
min1: + - - - - -
```

`A` 를 처음부터 끝까지 순회하면서 `max1, max2, max3, min2, min1` 을
갱신한다. 모든 반복이 끝나면 `max(max1*max2*max3, max1*min2*min1)` 이
답이다.

# Implementation

* [go](a.go)

# Complexity

```
O(N) O(1)
```
