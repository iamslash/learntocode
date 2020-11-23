# Problem

[Insert into a Cyclic Sorted List](https://leetcode.com/problems/insert-into-a-cyclic-sorted-list/)

# Idea

정렬된 순환 리스트의 헤드 `Node* h` 와 숫자 `v` 가 주어진다.  `v` 를
값으로 갖는 노드를 하나 만들어서 적당한 위치에 삽입하는 문제이다.

다음과 같이 두개의 `Node*` 를 선언한다.

```cpp
Node* b = h;
Node* p = h->next
```

선형 탐색하면서 적당한 위치에 삽입한다.

다음과 같은 다양한 예를 고려해보자.

```
h: 1->3->4 v: 2
   b  p
   1->2->3->4

h: 3->3->3 v: 2
   p     b
   2->3->3->3

h: 7->3->4 v: 2
   b  p
   7->2->3->4

h: 7->4->5 v: 3
   b  p
   7->2->3->4
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```
