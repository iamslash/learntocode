# Problem

[Add Two Polynomials Represented as Linked Lists](https://leetcode.com/problems/add-two-polynomials-represented-as-linked-lists/)

두개의 linked list 의 head node 가 주어진다. 
power 의 내림차순으로 linked list 를 구성하여 
merge 하고 새로운 head node 를 return 하라.

# Idea

`map<int, int> polyMap` 을 선언하고 `polyMap[power] = coefficent`
를 저장한다. 

`PolyNode head, PolyNode*p = &head` 를 선언한다.  `polyMap` 은 `power`
의 오름차순으로 정렬되어 있다. 거꾸로 순회하면서 `head` 를 완성한다.

모든 반복을 마치면 `head.next` 가 곧 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(NlgN) O(N)
```
