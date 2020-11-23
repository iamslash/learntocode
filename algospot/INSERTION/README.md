# Problem

[삽입 정렬 뒤집기 @ algospot](https://algospot.com/judge/problem/read/INSERTION)

# Idea

처음 N개 숫자들의 배열을 `A` 로 표기하고 `i` 번째 숫자를 `A[i]` 라고
하자. 삽입정렬을 수행할 때 `A[i]` 가 움직인 숫자를 `S[i]` 라고 하자.

`i` 를 `N-1` 부터 `0` 까지 순회하면서 `S[i]` 를 얻어 올 수
있다. `S[i]` 는 지금 시점에 `A[i]` 보다 큰 수의 개수를
의미한다. 그렇다면 ~보다 작거나 같은 수의 개수는 `N - S[i]` 라고 할 수
있다. 따라서 `S[i]` 를 이용하여 `A[i]` 가 얼만큼 작은 수 인지 알 수
있다.

[Treap::Kth](/doc/tree_treap.md)을 이용하면 몇 번째 작은 수를 `O(lgN)`
의 시간으로 찾아 낼 수 있다. Treap에 `1` 부터 `N` 까지 삽입한다.  `i`
를 `N-1` 부터 `0` 까지 순회하면서 `S[i]` 를 얻어오자. `N - S[i]` 번째
작은 수를 `A[i]` 에 저장하고 Treap에서 지우자. 언급한 `i` 의 순회를
마치면 `A[i]` 가 완성된다.

# Implementation

* [c++11](a.cpp)

# Time Complexity

```
O(NlgN)
```
