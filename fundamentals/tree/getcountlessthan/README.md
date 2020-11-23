# Problem

수열 `V` 와 숫자 `k` 가 주어진다. `u` 에서 `k` 번째 수를 구하는 문제이다.

# Idea

BBST (balanced binary search tree) 를 생성하고 검색한다. 비교적 구현이 쉬운 [treap](/fundamentals/tree/treap/README.md) 를 이용하자. 각 노드는 크기를 저장해야한다.

검색을 위해 다음과 같이 부분문제를 정의한다.

```cpp
Node * count_less_than(Node* u, int k)
```

그리고 다음과 같은 경우를 생각할 수 있다.

* `u == NULL` 인 경우 `0` 을 리턴한다
* `u->key >= key` 인 경우 `count_less_than(u->left, k)` 를 리턴한다.
* `u->key < key` 인 경우 `leftsize` 에 왼쪽 자식 노드들의 개수를 저장한다. 그리고 `leftsize + 1 + count_less_than(u->right, k)` 를 리턴한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
 build: O(NlgN) O(N)
search: O(lgN) O(lgN)
```