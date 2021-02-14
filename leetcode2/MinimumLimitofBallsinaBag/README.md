# Problem

[Minimum Limit of Balls in a Bag](https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/)

수열 `A[]`, 숫자 `k` 가 주어진다. `A[i]` 를 두개로 쪼개는 동작을 `k`
번까지 할 수 있다. 그때 가장 작은 `max(A[i])` 를 찾아라.

# Idea

예를 들어 `A = [9], k = 2` 인 경우를 살펴보자.

```
A: 9
   6 3
   3 3 3
```

따라서 답은 `3` 이다.

답의 후보값을 `m` 이라고 해보자. 예를 들어 `m = 9` 일 때를 살펴보자. `A[i] = 9`
인 경우 쪼개는 횟수는 0 이 나와야 한다. 그러나 `m = 8` 일 때를 살펴보자. `A[i] =
9` 인 경우 쪼개는 횟수는 1 이 나와야 한다. 따라서 `(A[i]-1)/m` 을 수행하면
쪼개는 횟수를 구할 수 있다.

이제 `m` 이 정해지면 `A[]` 를 순회하면서 쪼개는 횟수를 구할 수 있다.
이것의 숫자를 `cnt` 라고 하자. `cnt` 가 `k` 와 같을 때까지 `m`
을 탐색한다. [binary search](/fundamentals/search/binarysearch/README.md) 로 해결할 만하다.

# Implementation

* [java8](Solution.java)

# Complexity

```
O(Nlg10^9) O(1)
```
