# Problem

[Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/)

# Idea

링크드 리스트의 노드 `ListNode* h` 가 주어진다. 순서를 뒤집는
문제이다.

다음은 링크드 리스트 노드 `ListNode* h: 2 1` 를 뒤집는 과정이다.
`ListNode* p = NULL` 를 선언하여 `h` 의 이전 노드를 저장하고
`ListNode* n` 를 선언하여 `h->next` 를 백업한다.

`h != NULL` 인 동안 다음을 반복한다.

* `n = h->next` 를 수행한다.
* `h->next = p` 를 수행한다.
* `p = h` 
* `h = n`

```
         p                      p
p h      h      p h    p h      h      p h
  2 1    2 1    2 1    2 1    2 1    2 1
    n      n      n        n      n      n
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```
