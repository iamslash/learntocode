# Problem

* [Recover Binary Search Tree](https://leetcode.com/problems/recover-binary-search-tree/)

# Idea

BST 를 탐색해서 잘 못된 두개의 노드를 찾고 서로를 교체하여
Welformed BST 를 만드는 문제이다.

in-order traversal 를 이용하여 해결할 수 있다. 예를 들어
다음과 같은 트리를 in-order traversal 하면 `321` 이 된다.

```
   1
  /
 3
  \
   2
```

in-order traversal 이기 때문에 수열은 오름차순이 되어야 한다.
오름차순에 방해되는 수는 `3, 1` 이다. 따라서 이 둘을 교체하면
답이 된다.

이번에는 다음과 같은 트리를 살펴보자.

```
  3
 / \
1   4
   /
  2
```

in-order traversal 하면 `1324` 이다. 오름차순에 방해되는 숫자는
`3,2` 이다. 이 둘을 교체하면 답이된다.

잘못된 노드는 두개있다고 보장이 되므로 그것을 각각 `wrong_a, wrong_b` 에 저장하자. 그리고 현재 방문하는 노드와 크기를 비교할
이전노드를 `prev_p` 에 저장하자. in-order traversal 을 수행하면서
현재노드의 값과 `prev_p->val` 을 비교하여 BST 에 맞지 않으면 `wrong_a, wrong_b` 에 각각 저장하고 둘을 교체하면 Wellformed BST 를 구할 수 있다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```
