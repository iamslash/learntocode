# Problem

수열 `V` 와 숫자 `k` 가 주어진다. `u` 에서 `k` 번째 수를 구하는 문제이다.

# Idea

BBST (balanced binary search tree) 를 생성하고 검색한다. 비교적 구현이 쉬운 [treap](/fundamentals/tree/treap/README.md) 를 이용하자. 각 노드는 크기를 저장해야한다.

검색을 위해 다음과 같이 부분문제를 정의한다.

```cpp
Node * kth(Node* u, int k)
```

먼저 변수 `leftsize` 를 정의하고 왼쪽 자식노드의 크기 `u->left->size` 를 저장한다. 

그리고 다음과 같은 경우를 생각할 수 있다.

* `k == leftsize + 1` 인 경우 `u` 가 답이다.
* `k <= leftsize` 인 경우 `kth(u->left, k)` 를 리턴한다.
* `k > leftsize` 인 경우 `kth(u->right, k - leftsize - 1)` 를 리턴한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
 build: O(NlgN) O(N)
search: O(lgN) O(lgN)
```