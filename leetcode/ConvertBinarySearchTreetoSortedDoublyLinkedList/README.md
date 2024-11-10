# Problem

[Convert Binary Search Tree to Sorted Doubly Linked List](https://leetcode.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/)

Node `root` 가 주어진다. `root` 는 BST 의 root node 이다.  이 것을 오름차순으로 정렬한 cirular doubly-linked list 로 변환하라.

# Idea

다음과 같은 것들을 생각해 보자.

- BST 는 in-order traversal 하면 오름차순이 된다.
- in-order traversal 할 때 마다 이번에 방문한 node 를 `prev` 에 저장해 보자. 모든 순회를 마치면 `prev` 는 마지막 node 가 저장되어 있다.
- dummy node 를 만들어서 `dumm` 이라고 하자. `prev` 에 `dumm` 을 저장하고 in-order traversal 을 하자. 모든 순회를 마치면 `dumm.right` 은 list 의 첫 node 가 저장되어 있다.

모든 반복을 마치고 `dumm.right` 과 `prev` 를 연결하면 circular doubly-linked list 로 변활할 수 있다.

# Keyword

```
in-order, dummy node, prev node
```

# Implementation

* [c++11](a.cpp)
* [java17](MainApp.java)

# Complexity

```
O(N) O(lgN)
```
